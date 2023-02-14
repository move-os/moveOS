#include "inc/utilities/MCommTcpServer.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"


moveOS::utilities::comm::MCommTcpServer::MCommTcpServer(moveOS::base::MLogger* logger)
{
  this->logger = logger;
  this->socketFileDescriptor = -1;


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

