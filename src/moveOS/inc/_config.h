#ifndef _MOVE_OS_INC_CONFIG_H_
#define _MOVE_OS_INC_CONFIG_H_


/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Version info                                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define MOVE_OS_VERSION   0 /* TODO: Version update only upon getting ready for public use */





/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Target platform                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define PLATFORM_GNU_LINUX              0x00010000
#define PLATFORM_MAC_OS                 0x00020000
#define PLATFORM_WINDOWS                0x00040000

#define PLATFORM_FREE_RTOS              0x00100000
#define PLATFORM_AZURE_RTOS             0x00200000

#define PLATFORM_BAREMETAL_ARDUINO      0x01000000
#define PLATFORM_BAREMETAL_STM32F       0x02000000
#define PLATFORM_BAREMETAL_STM32H       0x04000000

#ifndef TARGET_PLATFORM
#define TARGET_PLATFORM PLATFORM_GNU_LINUX
#endif





/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Target architecture                                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define ARCHITECTURE_X86          0x00010000
#define ARCHITECTURE_ARM          0x00020000
#define ARCHITECTURE_AVR          0x00040000

#ifndef TARGET_ARCHITECTURE
#define TARGET_ARCHITECTURE ARCHITECTURE_X86
#endif












#endif