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
      };

    }
  }
}



#endif
