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
#define PLATFORM_WINDOWS
#define PLATFORM_LINUX
#define PLATFORM_ARDUINO
#define PLATFORM_STM32F4

#ifndef TARGET_PLATFORM
#define TARGET_PLATFORM PLATFORM_LINUX
#endif



#endif