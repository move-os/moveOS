#include "inc/utilities/MCommTcpServer.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"

#include <exception>


moveOS::utilities::comm::MCommTcpServer::MCommTcpServer(moveOS::base::MLogger* logger,
                                                        word listeningPort,
                                                        moveOS::base::MTcpDataEventWorkItem* packetHandlersChain,
                                                        tcp_server_new_connection_handler_func newConnectionHandler,
                                                        tcp_server_conn_close_handler_func connectionCloseHandler)
{
  this->logger = logger;

  this->packetHandlersChain = packetHandlersChain;
  this->newConnectionHandler = newConnectionHandler;
  this->connectionCloseHandler = connectionCloseHandler;

  this->socketFileDescriptor = -1;
  this->listeningPort = listeningPort;
  this->isServerRunning = false;
  this->isSocketOpen = false;
  this->isSocketBound = false;

  memset(&this->localSockAddr, 0, sizeof(this->localSockAddr));


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

moveOS::utilities::comm::MCommTcpServer::~MCommTcpServer()
{
  logger->logInfo("TCP Server at port %d being cleaned-up", listeningPort);

  StopServer();
}

int moveOS::utilities::comm::MCommTcpServer::RunServer()
{
  logger->logInfo("Starting-up TCP Server at port %d", listeningPort);

  return MTcpServerStatus::STOPPED;
}

int moveOS::utilities::comm::MCommTcpServer::StopServer()
{
  return MTcpServerStatus::STOPPED;
}

