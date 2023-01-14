#ifndef _MOVE_OS_INC_CONFIG_H_
#define _MOVE_OS_INC_CONFIG_H_


/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Version info                                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define MOVE_OS_VERSION   1





/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Target platform                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define PLATFORM_GNU_LINUX    0x00010000
#define PLATFORM_WINDOWS      0x00020000
#define PLATFORM_ARDUINO      0x00030000
#define PLATFORM_STM32F4      0x00040000

#ifndef TARGET_PLATFORM
#define TARGET_PLATFORM PLATFORM_GNU_LINUX
#endif












#endif