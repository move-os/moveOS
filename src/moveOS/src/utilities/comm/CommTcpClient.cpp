#include "inc/utilities/MCommTcpClient.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"

#include <exception>


moveOS::utilities::comm::MCommTcpClient::MCommTcpClient(moveOS::base::MLogger* logger,
                                                        byte* targetIpAddress, word targetPort,
                                                        bool isNonBlocking)
{
  this->logger = logger;

  this->targetIpAddress = targetIpAddress;
  this->targetPort = targetPort;

  this->isNonBlocking = isNonBlocking;

  this->isConnected = false;

  this->socketFileDescriptor = -1;

  memset(&this->targetSocketAddress, 0, sizeof(this->targetSocketAddress));

#if   TARGET_PLATFORM == PLATFORM_WINDOWS


  WSADATA wsaData;
  int windowsStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (windowsStartupResult != 0)
  {
    this->logger->logError("WSAStartup failed with return code: %d", windowsStartupResult);
    return;
  }


#endif
}

moveOS::utilities::comm::MCommTcpClient::~MCommTcpClient()
{
  Close();
}

bool moveOS::utilities::comm::MCommTcpClient::Connect()
{
  if (isConnected == false)
  {
    if (socketFileDescriptor == -1)
    {
      socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);

      if (socketFileDescriptor == -1)
      {
        logger->logError("Socket cannot be created for TCP Client connecting with %s:%d", targetIpAddress, targetPort);
        return false;
      }
    }



#if   TARGET_PLATFORM == PLATFORM_WINDOWS


    uint32 _temp;
    if (inet_pton(AF_INET, (const char*)targetIpAddress, &_temp) != 1)
    {
      struct addrinfo* result = NULL, hints;

      ZeroMemory(&hints, sizeof(hints));
      hints.ai_family = AF_UNSPEC;
      hints.ai_socktype = SOCK_STREAM;
      hints.ai_protocol = IPPROTO_TCP;

      char _target_port_str[7];
      sprintf_s(_target_port_str, "%d", targetPort);

      if (getaddrinfo((const char*)targetIpAddress, _target_port_str, &hints, &result) != 0)
      {
        logger->logError("Failed to resolve the hostname: %s", targetIpAddress);
        return false;
      }

      for (struct addrinfo* ptr = result; ptr != NULL; ptr = ptr->ai_next)
      {
        targetSocketAddress = *(struct sockaddr_in*)ptr->ai_addr;
        break;
      }
    }
    else
    {
      inet_pton(AF_INET, (const char*)targetIpAddress, &targetSocketAddress.sin_addr.s_addr);
    }


#elif TARGET_PLATFORM == PLATFORM_GNU_LINUX


    if (inet_addr((const char*)targetIpAddress) == -1)
    {
      struct hostent* he;
      struct in_addr** addr_list;

      if ((he = gethostbyname((const char*)targetIpAddress)) == NULL)
      {
        logger->logError("Failed to resolve the hostname: %s", targetIpAddress);
        return false;
      }

      addr_list = (struct in_addr**)he->h_addr_list;

      for (int i = 0; addr_list[i] != NULL; i++)
      {
        targetSocketAddress.sin_addr = *addr_list[i];
        break;
      }
    }
    else
    {
      targetSocketAddress.sin_addr.s_addr = inet_addr((const char*)targetIpAddress);
    }


#else
#error "No conversion of IP address defined for selected platform"
#endif
    

    targetSocketAddress.sin_family = AF_INET;
    targetSocketAddress.sin_port = htons(targetPort);

    if (connect(socketFileDescriptor,
                (struct sockaddr*)&targetSocketAddress,
                sizeof(targetSocketAddress)) < 0)
    {
      logger->logError("Unable to connect to %s:%d", targetIpAddress, targetPort);
      return false;
    }

    if (isNonBlocking)
    {

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
      int status = fcntl(socketFileDescriptor, F_SETFL, fcntl(socketFileDescriptor, F_GETFL, 0) | O_NONBLOCK);

      if (status == -1)
      {
        isNonBlocking = false;
        this->logger->logWarning("Unable to set TCP connection with %s:%d as non-blocking", targetIpAddress, targetPort);
      }


#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
      u_long mode = 1;
      int nonBlockingModeResult = ioctlsocket(socketFileDescriptor, FIONBIO, &mode);

      if (nonBlockingModeResult == SOCKET_ERROR)
      {
        this->logger->logWarning("Unable to set TCP connection with %s:%d as non-blocking", targetIpAddress, targetPort);
      }

#else
#error "Cannot set socket to non-blocking for selected platform"

#endif
      
    }

    isConnected = true;
  }

  return isConnected;
}

bool moveOS::utilities::comm::MCommTcpClient::IsConnected()
{
  return isConnected;
}

void moveOS::utilities::comm::MCommTcpClient::Close()
{
  if (IsConnected())
  {

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
    close(socketFileDescriptor);

#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
    closesocket(socketFileDescriptor);

#else
#error "Cannot close socket on selected platform"

#endif

    socketFileDescriptor = -1;
    isConnected = false;
  }
}

bool moveOS::utilities::comm::MCommTcpClient::IsPacketAvailable(word timeoutSecond, word timeoutMicrosecond)
{
  if (isNonBlocking)
  {
    timeval tv;
    fd_set readfds;

    tv.tv_sec = timeoutSecond;
    tv.tv_usec = timeoutMicrosecond;

    FD_ZERO(&readfds);
    FD_SET(socketFileDescriptor, &readfds);

    // don't care about write and exception descriptors
    select(socketFileDescriptor + 1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(socketFileDescriptor, &readfds))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  return true;
}

word moveOS::utilities::comm::MCommTcpClient::SendMessage(const byte* buffer, word numBytes)
{
  if (IsConnected() && numBytes > 0)
  {
    try
    {
      send(socketFileDescriptor, (const char*)buffer, numBytes, 0);
    }
    catch (std::exception& ex)
    {
      logger->logError("FD=[%d] Socket exception caught while sending packet: %s", socketFileDescriptor, ex.what());
      return 0;
    }

    return numBytes;
  }

  return 0;
}

word moveOS::utilities::comm::MCommTcpClient::ReceiveMessage(byte* buffer, word buffSize)
{
  int numBytesReceived = 0;

  if (IsConnected())
  {
    try
    {
      if ((numBytesReceived = recv(socketFileDescriptor, (char*)buffer, buffSize, 0)) <= 0)
      {
        if (numBytesReceived == 0)
        {
          logger->logError("FD=[%d] connection closed by server [%s:%d]", socketFileDescriptor, targetIpAddress, targetPort);
        }
        else
        {
          logger->logError("FD=[%d] connection ERROR with server [%s:%d]", socketFileDescriptor, targetIpAddress, targetPort);
        }

        Close();

        return 0;
      }

      return (unsigned int)numBytesReceived;
    }
    catch (std::exception& ex)
    {
      logger->logError("FD=[%d] Exception in Sockets area: %s", socketFileDescriptor, ex.what());
    }
  }

  return 0;
}
