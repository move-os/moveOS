#ifndef _MOVE_OS_INC_UTILITIES_M_COMM_UDP_CLIENT_H_
#define _MOVE_OS_INC_UTILITIES_M_COMM_UDP_CLIENT_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace utilities
  {
    namespace comm
    {
      
      class MCommUdpClient
      {
      public:
        MCommUdpClient(word localPort = MLocalPort::ANY,
                       bool enableBroadcasting = false,
                       bool isNonBlocking = false);
        ~MCommUdpClient();

        bool IsSocketCreated();
        bool IsSocketBound();

        void Close();

        bool IsPacketAvailable(int timeoutSecond, int timeoutMicrosecond);

        void SendMessage(const char* buffer, unsigned int numBytes, const char* targetIP, word targetPort);

        packet_info ReceiveMessage(unsigned char* buffer, unsigned int bufSize);

        packet_info ReceiveEncryptedMessage(unsigned char* buffer, unsigned int bufSize);


      private:
        int _sockFD;
        ushort localBoundPort;
        bool isSocketBound;
        bool isBroadcastingSocket;
        bool isNonBlockingSocket;
        sockaddr_in localSockAddr;
        sockaddr_in targetSockAddr;
      };

    }
  }
}



#endif
