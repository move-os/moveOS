#include "inc/utilities/MCommUdpClient.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"


moveOS::utilities::comm::MCommUdpClient::MCommUdpClient(
  moveOS::base::MLogger* logger,
  word localPort,
  bool enableBroadcasting,
  bool isNonBlocking)
{
  this->logger = logger;
  this->_sockFD = -1;
  this->localBoundPort = localPort;
  this->isSocketBound = false;
  this->isBroadcastingSocket = false;
  this->isNonBlockingSocket = isNonBlocking;
  memset(&this->localSockAddr, 0, sizeof(this->localSockAddr));
  memset(&this->targetSockAddr, 0, sizeof(this->targetSockAddr));



#if   TARGET_PLATFORM == PLATFORM_WINDOWS


  WSADATA wsaData;
  int windowsStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (windowsStartupResult != 0)
  {
    this->logger->logError("WSAStartup failed with return code: %d", windowsStartupResult);
    return;
  }


#endif



  this->_sockFD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (this->_sockFD < 0)
  {
    this->logger->logError("UDP socket creation failed");
    return;
  }

  if (enableBroadcasting)
  {
    int broadcastPermission = 1;
    int socketOptionsResult = setsockopt(_sockFD,
                                         SOL_SOCKET,
                                         SO_BROADCAST,
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
                                         (void*)&broadcastPermission,
#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
                                         (const char*)&broadcastPermission,
#else
#error "Cannot set socket options for selected platform"
#endif
                                         sizeof(broadcastPermission));
    
    if (socketOptionsResult < 0)
    {
      this->logger->logError("Setting UDP socket for broadcasting failed");
      this->isBroadcastingSocket = false;
    }
    else
    {
      this->logger->logInfo("Successfully setting UDP socket for broadcasting");
      this->isBroadcastingSocket = true;
    }
  }

  if (localPort != MUdpPort::ANY)
  {
    localSockAddr.sin_family = AF_INET;
    localSockAddr.sin_addr.s_addr = htonl(isBroadcastingSocket ? INADDR_BROADCAST : INADDR_ANY);
    localSockAddr.sin_port = htons(localBoundPort);

    if (bind(_sockFD, (struct sockaddr*)&localSockAddr, sizeof(localSockAddr)) < 0)
    {
      this->logger->logError("Socket binding error @%d", (int)localBoundPort);
      this->isSocketBound = false;
    }
    else
    {
      this->isSocketBound = true;
    }
  }

  if (isNonBlocking)
  {
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
    fcntl(_sockFD, F_SETFL, O_NONBLOCK);
    
#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
    u_long mode = 1;
    int nonBlockingModeResult = ioctlsocket(_sockFD, FIONBIO, &mode);

    if (nonBlockingModeResult == SOCKET_ERROR)
    {
      this->logger->logError("Setting socket @%d to non-blocking mode failed", (int)localBoundPort);
    }

#else
#error "Cannot set socket to non-blocking for selected platform"
#endif
  }

  isNonBlockingSocket = isNonBlocking;
}

moveOS::utilities::comm::MCommUdpClient::~MCommUdpClient()
{
  Close();
}

bool moveOS::utilities::comm::MCommUdpClient::IsSocketCreated()
{
  return _sockFD >= 0;
}

bool moveOS::utilities::comm::MCommUdpClient::IsSocketBound()
{
  return isSocketBound;
}

bool moveOS::utilities::comm::MCommUdpClient::IsSocketBroadcasting()
{
  return isBroadcastingSocket;
}

void moveOS::utilities::comm::MCommUdpClient::Close()
{
  if (IsSocketCreated())
  {
    
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
    close(_sockFD);

#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
    closesocket(_sockFD);

#else
#error "Cannot close socket for selected platform"

#endif

    _sockFD = -1;
    isSocketBound = false;
    isBroadcastingSocket = false;
  }
}

bool moveOS::utilities::comm::MCommUdpClient::IsPacketAvailable(word timeoutSecond, word timeoutMicrosecond)
{
  if (isNonBlockingSocket)
  {
    timeval tv;
    fd_set readfds;

    tv.tv_sec = timeoutSecond;
    tv.tv_usec = timeoutMicrosecond;

    FD_ZERO(&readfds);
    FD_SET(_sockFD, &readfds);

    // don't care about write and exception descriptors
    select((int)_sockFD + 1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(_sockFD, &readfds))
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

void moveOS::utilities::comm::MCommUdpClient::SendMessage(const byte* buffer, word numBytes, const byte* targetIP, word targetPort)
{
  if (!IsSocketCreated()) return;

  memset(&targetSockAddr, 0, sizeof(targetSockAddr));

  targetSockAddr.sin_family = AF_INET;

#if   TARGET_PLATFORM == PLATFORM_WINDOWS
  inet_pton(AF_INET, (const char*)targetIP, &targetSockAddr.sin_addr.s_addr);

#else
  targetSockAddr.sin_addr.s_addr = inet_addr((const char*)targetIP);

#endif

  targetSockAddr.sin_port = htons(targetPort);

  sendto(_sockFD, (const char*)buffer, numBytes, 0, (struct sockaddr*)&targetSockAddr, sizeof(targetSockAddr));
}

packet_info moveOS::utilities::comm::MCommUdpClient::ReceiveMessage(byte* buffer, word buffSize)
{
  packet_info info;

#if   TARGET_PLATFORM == PLATFORM_WINDOWS
  int slen = (int)sizeof(targetSockAddr);
#else
  unsigned int slen = (unsigned int)sizeof(targetSockAddr);
#endif

  info.numBytesReceived =
    recvfrom(_sockFD, (char*)buffer, buffSize, 0, (struct sockaddr*)&targetSockAddr, &slen);

  if (info.numBytesReceived < 0)
  {
    info.receivedFromIP[0] = 0;
    info.receivedFromPort = 0;
    return info;
  }

#if   TARGET_PLATFORM == PLATFORM_WINDOWS
  inet_ntop(AF_INET, &targetSockAddr.sin_addr, (char*)info.receivedFromIP, sizeof(info.receivedFromIP));

#elif TARGET_PLATFORM == PLATFORM_GNU_LINUX
  strcpy((char*)info.receivedFromIP, (const char*)inet_ntoa(targetSockAddr.sin_addr));

#else
#error "No conversion of IP address defined for selected platform"

#endif

  info.receivedFromPort = ntohs(targetSockAddr.sin_port);

  return info;
}
