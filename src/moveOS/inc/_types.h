#ifndef _MOVE_OS_INC_TYPES_H_
#define _MOVE_OS_INC_TYPES_H_



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
