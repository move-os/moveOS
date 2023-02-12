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
      this->logger->logError("Socket Binding error @%d", (int)localBoundPort);
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
}

bool moveOS::utilities::comm::MCommUdpClient::IsPacketAvailable(word timeoutSecond, word timeoutMicrosecond)
{
  return false;
}

void moveOS::utilities::comm::MCommUdpClient::SendMessage(const byte* buffer, word numBytes, const byte* targetIP, word targetPort)
{
}

packet_info moveOS::utilities::comm::MCommUdpClient::ReceiveMessage(byte* buffer, word buffSize)
{
  return packet_info();
}
