#ifndef _MOVE_OS_INC_UTILITIES_M_COMM_TCP_SERVER_H_
#define _MOVE_OS_INC_UTILITIES_M_COMM_TCP_SERVER_H_

#include "_config.h"


#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>




#elif   TARGET_PLATFORM == PLATFORM_WINDOWS

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <fcntl.h>

#pragma comment(lib, "ws2_32.lib")




#else

//- 




#endif


#include "_types.h"


namespace moveOS
{
  namespace base
  {
    class MLogger;
    class MTcpDataEventWorkItem;
  }
}


namespace moveOS
{
  namespace utilities
  {
    namespace comm
    {

      class MCommTcpServer
      {
      public:
        MCommTcpServer(moveOS::base::MLogger* logger,
                       word listeningPort,
                       moveOS::base::MTcpDataEventWorkItem* packetHandlersChain,
                       tcp_server_conn_close_handler_func connectionCloseHandler);


      private:
        moveOS::base::MLogger* logger;

        socket_desc_t socketFileDescriptor;
        word listeningPort;
        moveOS::base::MTcpDataEventWorkItem* packetHandlersChain;
        tcp_server_conn_close_handler_func connectionCloseHandler;
      };

    }
  }
}



#endif
