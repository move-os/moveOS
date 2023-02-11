#include "inc/utilities/MCommUdpClient.h"

#include "src/_internal_inc/macros.h"


moveOS::utilities::comm::MCommUdpClient::MCommUdpClient(
  word localPort,
  bool enableBroadcasting,
  bool isNonBlocking)
{

}

moveOS::utilities::comm::MCommUdpClient::~MCommUdpClient()
{
}

bool moveOS::utilities::comm::MCommUdpClient::IsSocketCreated()
{
  return false;
}

bool moveOS::utilities::comm::MCommUdpClient::IsSocketBound()
{
  return false;
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
