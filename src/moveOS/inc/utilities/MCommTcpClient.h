#ifndef _MOVE_OS_INC_UTILITIES_M_COMM_TCP_CLIENT_H_
#define _MOVE_OS_INC_UTILITIES_M_COMM_TCP_CLIENT_H_

#include "_config.h"


#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
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
  }
}


namespace moveOS
{
  namespace utilities
  {
    namespace comm
    {

      class MCommTcpClient
      {
      public:
        MCommTcpClient(moveOS::base::MLogger* logger,
                       byte* targetIpAddress, word targetPort,
                       bool isNonBlocking = true);

        ~MCommTcpClient();

        bool Connect();
        bool IsConnected();

        void Close();

        bool IsPacketAvailable(word timeoutSecond, word timeoutMicrosecond);

        word SendMessage(const byte* buffer, word numBytes);   // RETURN: Number of bytes sent
        word ReceiveMessage(byte* buffer, word buffSize);      // RETURN: Number of bytes received


      private:
        moveOS::base::MLogger* logger;

        socket_desc_t socketFileDescriptor;
        
        byte* targetIpAddress;
        word targetPort;
        sockaddr_in targetSocketAddress;

        bool isNonBlocking;
        bool isConnected;
      };

    }
  }
}



#endif
