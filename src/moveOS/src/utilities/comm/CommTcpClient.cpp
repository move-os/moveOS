#include "inc/utilities/MCommTcpClient.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"


moveOS::utilities::comm::MCommTcpClient::MCommTcpClient(moveOS::base::MLogger* logger,
                                                        byte* targetIpAddress, word targetPort,
                                                        bool isNonBlocking = true)
{
  this->logger = logger;

  this->targetIpAddress = targetIpAddress;
  this->targetPort = targetPort;

  this->isNonBlocking = isNonBlocking;

  this->isConnected = false;

  this->socketFileDescriptor = -1;
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
#if   TARGET_PLATFORM == PLATFORM_WINDOWS
      inet_pton(AF_INET, (const char*)targetIpAddress, &targetSocketAddress.sin_addr.s_addr);

#else
      targetSocketAddress.sin_addr.s_addr = inet_addr((const char*)targetIpAddress);

#endif
    }

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
    close(_sockFD);

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
  return word();
}

word moveOS::utilities::comm::MCommTcpClient::ReceiveMessage(byte* buffer, word buffSize)
{
  return word();
}
