#include "inc/utilities/MCommTcpClient.h"

#include "src/_internal_inc/macros.h"


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
  return false;
}

word moveOS::utilities::comm::MCommTcpClient::SendMessage(const byte* buffer, word numBytes)
{
  return word();
}

word moveOS::utilities::comm::MCommTcpClient::ReceiveMessage(byte* buffer, word buffSize)
{
  return word();
}
