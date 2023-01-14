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

typedef    int8                              INT8      ;
typedef    uint8                            UINT8      ;
typedef    int16                             INT16     ;
typedef    uint16                           UINT16     ;
typedef    int32                             INT32     ;
typedef    uint32                           UINT32     ;
typedef    int64                             INT64     ;
typedef    uint64                           UINT64     ;

typedef    float                            single     ;
typedef    single                           SINGLE     ;
typedef    double                           DOUBLE     ;



/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Function types                                                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
typedef    void(*simple_func)();
typedef    void(*nret_vptr1_func)(void*);
typedef    void(*nret_vptr2_func)(void*, void*);

typedef    INT8(*i8ret_func)();
typedef    INT8(*i8ret_vptr1_func)(void*);
typedef    INT8(*i8ret_vptr2_func)(void*, void*);

typedef    INT16(*i16ret_func)();
typedef    INT16(*i16ret_vptr1_func)(void*);
typedef    INT16(*i16ret_vptr2_func)(void*, void*);

typedef    INT32(*i32ret_func)();
typedef    INT32(*i32ret_vptr1_func)(void*);
typedef    INT32(*i32ret_vptr2_func)(void*, void*);

typedef    UINT8(*ui8ret_func)();
typedef    UINT8(*ui8ret_vptr1_func)(void*);
typedef    UINT8(*ui8ret_vptr2_func)(void*, void*);

typedef    UINT16(*ui16ret_func)();
typedef    UINT16(*ui16ret_vptr1_func)(void*);
typedef    UINT16(*ui16ret_vptr2_func)(void*, void*);

typedef    UINT32(*ui32ret_func)();
typedef    UINT32(*ui32ret_vptr1_func)(void*);
typedef    UINT32(*ui32ret_vptr2_func)(void*, void*);







#endif
