#ifndef _MOVE_OS_INC_TYPES_H_
#define _MOVE_OS_INC_TYPES_H_

#include "_config.h"




/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Simple datatypes                                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

typedef             char                     int8      ;
typedef    unsigned char                    uint8      ;
typedef             short                    int16     ;
typedef    unsigned short                   uint16     ;
typedef             long                     int32     ;
typedef    unsigned long                    uint32     ;
typedef             long long                int64     ;
typedef    unsigned long long               uint64     ;

typedef    uint8                             byte      ;
typedef    uint16                            word      ;
typedef    uint32                            dword     ;
typedef    uint64                            qword     ;

typedef    int8                              sbyte     ;
typedef    int16                             sword     ;
typedef    int32                             sdword    ;
typedef    int64                             sqword    ;

typedef    float                            single     ;





/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Compound types                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

struct MEventPollResult
{
  enum {
    NONE,
    RAISE_EVENT
  };
};

struct MEventWorkItemResult
{
  enum {
    KEEP_CHAINING,
    BREAK_FURTHER_CHAIN
  };
};

typedef enum {
  LOG_ERROR,
  LOG_WARNING,
  LOG_INFO
} log_level;

struct MUdpPort
{
  enum {
    ANY = 0,
    TCPMUX = 1,                        // TCP port multiplexer
    RJE = 5,                           // Remote job entry
    ECHO = 7,                          // Echo service
    DISCARD = 9,                       // Zero service for test purposes
    SYS_STAT = 11,                     // System information
    DAYTIME = 13,                      // Time and date
    QOTD = 17,                         // Sends quote of the day
    MSP = 18,                          // Sends text messages
    CHARGEN = 19,                      // Sends an infinite character string
    FTP = 21,                          // FTP connection
    SSH = 22,                          // Secure Shell Service
    TIME = 37,                         // Machine-readable time protocol
    RLP = 39,                          // Resource location protocol
    NAMESERVER = 42,                   // Name service
    TAC_ACS = 49,                      // Terminal access controller access control system
    RE_MAIL_CK = 50,                   // Remote mail checking
    DOMAIN = 53,                       // DNS name resolver
    BOOT_PS = 67,                      // Bootstrap protocol services
    BOOT_PC = 68,                      // Bootstrap client
    TFTP = 69,                         // Trivial file transfer protocol
    TORPARK = 82,                      // Torpark: Control (unofficial)
    KERBEROS = 88,                     // Network authentication system
    CSNET_NS = 105,                    // Mailbox mail server
    SUNRPC = 111,                      // RPC protocol for NFS
    AUTH = 113,                        // Authentication service
    NTP = 123,                         // Time synchronization service
    NETBIOS_NS = 137,                  // NETBIOS name service
    NETBIOS_DGM = 138,                 // NETBIOS datagram service
    NETBIOS_SSN = 139,                 // NETBIOS session service
    IMAP = 143,                        // Internet message access protocol for e-mail communication
    SNMP = 161,                        // Simple network management protocol
    SNMP_TRAP = 162,                   // Simple network management protocol trap
    XDMCP = 177,                       // X display manager
    IRC = 194,                         // Internet relay chat
    SMUX = 199,                        // SNMP UNIX multiplexer
    AT_RTMP = 201,                     // AppleTalk routing
    QMTP = 209,                        // Quick mail transfer protocol
    Z39_PT_50 = 210,                   // Bibliographic information system
    IPX = 213,                         // Internetwork packet exchange
    IMAP3 = 220,                       // IMAP v3 for e-mail communication
    RPC_2_PORTMAP = 369,               // Coda file system port mapper
    CODA_AUTH2 = 370,                  // Coda file system authentication service
    LDAP = 389,                        // Lightweight directory access protocol
    SVR_LOC = 427,                     // Service location protocol
    SNPP = 444,                        // Simple network paging protocol
    KPASSWD = 464,                     // Kerberos password change
    ISAKMP = 500,                      // Security protocol
    COMSAT_BIFF = 512,                 // Mail client and server
    WHO = 513,                         // Whod user logging daemon
    SYSLOG = 514,                      // Unix system logging service
    TALK = 517,                        // Talk remote calling
    NTALK = 518,                       // Network talk
    ROUTER = 520,                      // Routing information protocol
    RIPNG = 521,                       // Routing information protocol for IPv6
    TIMED = 525,                       // Time server
    COURIER = 530,                     // Courier remote procedure call
    CONFERENCE = 531,                  // Chat over AIM and IRC
    NETWALL = 533,                     // Emergency broadcasts
    DHCP_V6_CLIENT = 546,              // DHCP v6 client
    DHCP_V6_SERVER = 547,              // DHCP v6 server
    RTSP = 554,                        // Realtime streaming protocol
    NNTPS = 563,                       // NNTP over SSL/TLS
    IPP = 631,                         // Internet printing protocol
    UNIX_PRINTING = 631,               // Common Unix printing system (unofficial)
    LDAPS = 636,                       // LDAP over SSL/TLS
    HA_CLUSTER = 694,                  // Heartbeat service
    KERBEROS_ADM = 749,                // Kerberos v5 administration
    KERBEROS_IV = 750,                 // Kerberos v4 services
    TELNETS = 992,                     // Telnet over SSL/TLS
    MICROSOFT_SQL_M = 1434,            // Microsoft SQL monitor
    WINS = 1512,                       // Windows internet name service
    INGRES_LOCK = 1524,                // Ingres DBMS
    L2TP = 1701,                       // Layer 2 tunneling protocol/Layer 2 forwarding
    H323_GATE_STAT = 1719,             // H.323
    RADIUS = 1812,                     // RADIUS authentication
    RADIUS_ACCT = 1813,                // RADIUS access
    HSRP = 1985,                       // Cisco HSRP
    TEAMSPEAK_3_WEB = 2010,            // Teamspeak 3 web list (unofficial)
    NFS = 2049,                        // Network file system
    ZEPHYR_SRV = 2102,                 // Zephyr server
    ZEPHYR_CLT = 2103,                 // Zephyr client
    ZEPHYR_HM = 2104,                  // Zephyr host manager
    CORBALOC = 2809,                   // Common object request broker architecture
    MYSQL = 3306,                      // MySQL database service (also for MariaDB)
    BPRD = 13720,                      // Symantec/Veritas NetBackup
    BPDBM = 13721,                     // Symantec/Veritas database manager
    VNETD = 13724,                     // Symantec/Veritas network utility
    BPCD = 13782,                      // Symantec/Veritas NetBackup
    VOPIED = 13783,                    // Symantec/Veritas VOPIE
    WNN6 = 22273,                      // Kana/Kanji conversion
    SKYPE = 23399,                     // Skype (unofficial)
    QUAKE = 26000,                     // Quake and other multiplayer games
    MONGO_DB = 27017,                  // MongoDB
    TRACE_ROUTE = 33434,               // Network tracking
  };
};

struct MTcpPort
{
  enum {
    ANY = 0,
    TCPMUX = 1,                        // TCP port multiplexer
    RJE = 5,                           // Remote job entry
    ECHO = 7,                          // Echo service
    DISCARD = 9,                       // Zero service for test purposes
    SYS_STAT = 11,                     // System information
    DAYTIME = 13,                      // Time and date
    QOTD = 17,                         // Sends quote of the day
    MSP = 18,                          // Sends text messages
    CHARGEN = 19,                      // Sends an infinite character string
    FTP_DATA = 20,                     // FTP data transfer
    FTP = 21,                          // FTP connection
    SSH = 22,                          // Secure Shell Service
    TELNET = 23,                       // Telnet service
    SMTP = 25,                         // Simple Mail Transfer Protocol
    TIME = 37,                         // Machine-readable time protocol
    RLP = 39,                          // Resource location protocol
    NAME_SERVER = 42,                  // Name service
    NIC_NAME = 43,                     // WHOIS directory service
    TACACS = 49,                       // Terminal access controller access control system
    RE_MAIL_CK = 50,                   // Remote mail checking
    DOMAIN = 53,                       // DNS name resolver
    GOPHER = 70,                       // Document search
    GENIUS = 71,                       // Genius protocol
    FINGER = 79,                       // Delivers user contact information
    HTTP = 80,                         // Hypertext transfer protocol
    TORPARK = 81,                      // Torpark: Onion routing (unofficial)
    KERBEROS = 88,                     // Network authentication system
    HOST_NAME = 101,                   // NIC host name
    ISO_TSAP = 102,                    // ISO TSAP protocol
    CSNET_NS = 105,                    // Mailbox mail server
    RTELNET = 107,                     // Remote telnet
    POP2 = 109,                        // Post office protocol v2 for e-mail communication
    POP3 = 110,                        // Post office protocol v3 for e-mail communication
    SUNRPC = 111,                      // RPC protocol for NFS
    SFTP = 115,                        // Simple file transfer protocol
    UUCP_PATH = 117,                   // File transfer between Unix systems
    NNTP = 119,                        // Transfer of messages in news groups
    NETBIOS_NS = 137,                  // NETBIOS name service
    NETBIOS_DGM = 138,                 // NETBIOS datagram service
    NETBIOS_SSN = 139,                 // NETBIOS session service
    IMAP = 143,                        // Internet message access protocol for e-mail communication
    SNMP_TRAP = 162,                   // Simple network management protocol trap
    XDMCP = 177,                       // X display manager
    BGP = 179,                         // Border gateway protocol
    IRC = 194,                         // Internet relay chat
    SMUX = 199,                        // SNMP UNIX multiplexer
    AT_RTMP = 201,                     // AppleTalk routing
    QMTP = 209,                        // Quick mail transfer protocol
    Z39_PT_50 = 210,                   // Bibliographic information system
    IPX = 213,                         // Internetwork packet exchange
    IMAP3 = 220,                       // IMAP v3 for e-mail communication
    RPC2PORTMAP = 369,                 // Coda file system port mapper
    CODA_AUTH2 = 370,                  // Coda file system authentication service
    LDAP = 389,                        // Lightweight directory access protocol
    SVRLOC = 427,                      // Service location protocol
    HTTPS = 443,                       // HTTPS (HTTP over SSL/TLS)
    SNPP = 444,                        // Simple network paging protocol
    MICROSOFT_DS = 445,                // SMB over TCP/IP
    KPASSWD = 464,                     // Kerberos password change
    EXEC = 512,                        // Remote process execution
    LOGIN = 513,                       // Login to remote computer
    SHELL = 514,                       // Remote shell
    PRINTER = 515,                     // Line printer daemon print services
    EFS = 520,                         // Extended file name server
    COURIER = 530,                     // Courier remote procedure call
    CONFERENCE = 531,                  // Chat over AIM and IRC
    NETNEWS = 532,                     // Netnews newsgroup service
    UUCP = 540,                        // Unix-to-Unix copy protocol
    KLOGIN = 543,                      // Kerberos v5 remote login
    KSHELL = 544,                      // Kerberos v5 remote shell
    DHCP_V6_CLIENT = 546,              // DHCP v6 client
    DHCP_V6_SERVER = 547,              // DHCP v6 server
    AFP_OVER_TCP = 548,                // Apple filing protocol over TCP
    RTSP = 554,                        // Realtime streaming protocol
    REMOTE_FS = 556,                   // Remote file system
    NNTPS = 563,                       // NNTP over SSL/TLS
    SUBMISSION = 587,                  // Message submission agent
    IPP = 631,                         // Internet printing protocol
    UNIX_PRINTING = 631,               // Common Unix printing system (unofficial)
    LDAPS = 636,                       // LDAP over SSL/TLS
    ACAP = 674,                        // Application configuration access protocol
    HA_CLUSTER = 694,                  // Heartbeat service
    KERBEROS_ADM = 749,                // Kerberos v5 administration
    RSYNC = 873,                       // rsync file transfer services
    TELNETS = 992,                     // Telnet over SSL/TLS
    IMAPS = 993,                       // IMAP over SSL/TLS
    POP3S = 995,                       // POP3 over SSL/TLS
    SOCKS = 1080,                      // SOCKS proxy
    MICROSOFT_SQL_S = 1433,            // Microsoft SQL server
    MICROSOFT_SQL_M = 1434,            // Microsoft SQL monitor
    ICA = 1494,                        // Citrix ICA client
    WINS = 1512,                       // Windows internet name service
    INGRES_LOCK = 1524,                // Ingres DBMS
    H323_HOST_CALL = 1720,             // H.323
    RADIUS = 1812,                     // RADIUS authentication
    RADIUS_ACCT = 1813,                // RADIUS access
    TEAMSPEAK_3_ACC = 2008,            // Teamspeak 3 accounting (unofficial)
    NFS = 2049,                        // Network file system
    ZEPHYR_SRV = 2102,                 // Zephyr server
    ZEPHYR_CLT = 2103,                 // Zephyr client
    ZEPHYR_HM = 2104,                  // Zephyr host manager
    CVSP_SERVER = 2401,                // Concurrent versions system
    CORBALOC = 2809,                   // Common object request broker architecture
    MYSQL = 3306,                      // MySQL database service (also for MariaDB)
    RWHOIS = 4321,                     // Remote whois service
    CVSUP = 5999,                      // CVSup
    X11 = 6000,                        // X11	X Windows system services
    PGP_KEY_SERVER = 11371,            // Public keyserver for PGP
    BPRD = 13720,                      // Symantec/Veritas NetBackup
    BPDBM = 13721,                     // Symantec/Veritas database manager
    VNETD = 13724,                     // Symantec/Veritas network utility
    BPCD = 13782,                      // Symantec/Veritas NetBackup
    VOPIED = 13783,                    // Symantec/Veritas VOPIE
    WNN6 = 22273,                      // Kana/Kanji conversion
    SKYPE = 23399,                     // Skype (unofficial)
    MINECRAFT = 25565,                 // Minecraft
    QUAKE = 26000,                     // Quake and other multiplayer games
    MONGO_DB = 27017,                  // MongoDB
    TRACE_ROUTE = 33434,               // Network tracking
  };
};

typedef struct
{
  word numBytesReceived;
  byte* receivedFromIP;
  word receivedFromPort;
} packet_info;





/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Function types                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/**
* Checks for the presence of an event.
* Returns:
*   -1 => Event is not required to be raised
*   ~  => Event should be raised
*/
typedef    byte(*event_poll_func)();



/**
* When handling an event, return:
*   MEventWorkItemResult::KEEP_CHAINING       => Keep chaining when chained call
*   MEventWorkItemResult::BREAK_FURTHER_CHAIN => Stop further chained calls
*/

typedef    void(*simplest_func)();
typedef    byte(*code_ret_simple_func)();
typedef    byte(*byte_data_handler_func)(byte);
typedef    byte(*data_handler_func)(byte*, uint16);
typedef    byte(*integral_data_handler_func)(uint16);

typedef    void(*nret_vptr1_func)(void*);
typedef    void(*nret_vptr2_func)(void*, void*);

typedef    int8(*i8ret_func)();
typedef    int8(*i8ret_vptr1_func)(void*);
typedef    int8(*i8ret_vptr2_func)(void*, void*);

typedef    int16(*i16ret_func)();
typedef    int16(*i16ret_vptr1_func)(void*);
typedef    int16(*i16ret_vptr2_func)(void*, void*);

typedef    int32(*i32ret_func)();
typedef    int32(*i32ret_vptr1_func)(void*);
typedef    int32(*i32ret_vptr2_func)(void*, void*);

typedef    uint8(*ui8ret_func)();
typedef    uint8(*ui8ret_vptr1_func)(void*);
typedef    uint8(*ui8ret_vptr2_func)(void*, void*);

typedef    uint16(*ui16ret_func)();
typedef    uint16(*ui16ret_vptr1_func)(void*);
typedef    uint16(*ui16ret_vptr2_func)(void*, void*);

typedef    uint32(*ui32ret_func)();
typedef    uint32(*ui32ret_vptr1_func)(void*);
typedef    uint32(*ui32ret_vptr2_func)(void*, void*);











#endif
