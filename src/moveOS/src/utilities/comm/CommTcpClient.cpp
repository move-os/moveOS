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