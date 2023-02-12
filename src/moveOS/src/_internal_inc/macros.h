#ifndef _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_
#define _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_

#include "_types.h"
#include "_config.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>





#define STR_RTRIM(x) {uint16 __inr_=0;while(x[__inr_]!=' ' && x[__inr_]!='\0')__inr_++;x[__inr_]='\0';}
#define STR_LTRIM(x) {uint16 __nsl_=0,__inl_=0;while(x[__nsl_]==' ')__nsl_++;while(x[__nsl_]!='\0'){x[__inl_]=x[__nsl_];__inl_++;__nsl_++;}x[__inl_]='\0';}
#define STR_TRIM(x) STR_LTRIM(x) STR_RTRIM(x)





#if   TARGET_PLATFORM == PLATFORM_WINDOWS

#define     __SPRINTF_REPLACEMENT_001__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "00000000");
#define     __SPRINTF_REPLACEMENT_002__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "0000000000000000");
#define     __SPRINTF_REPLACEMENT_003__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "000000000000000000000000");
#define     __SPRINTF_REPLACEMENT_004__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "00000000000000000000000000000000");
#define     __SPRINTF_REPLACEMENT_005__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "0");
#define     __SPRINTF_REPLACEMENT_006__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "%c", va_arg(__va_args__, int));
#define     __SPRINTF_REPLACEMENT_007__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "%d", va_arg(__va_args__, int));
#define     __SPRINTF_REPLACEMENT_008__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "%u", va_arg(__va_args__, unsigned int));
#define     __SPRINTF_REPLACEMENT_009__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "%x", va_arg(__va_args__, unsigned int));
#define     __SPRINTF_REPLACEMENT_010__     sprintf_s(&message[__message_index__], LOGGER_MESSAGE_STRING_BUFFER_SIZE - __message_index__, "%X", va_arg(__va_args__, unsigned int));




#else

#define     __SPRINTF_REPLACEMENT_001__     sprintf(&message[__message_index__], "00000000");
#define     __SPRINTF_REPLACEMENT_002__     sprintf(&message[__message_index__], "0000000000000000");
#define     __SPRINTF_REPLACEMENT_003__     sprintf(&message[__message_index__], "000000000000000000000000");
#define     __SPRINTF_REPLACEMENT_004__     sprintf(&message[__message_index__], "00000000000000000000000000000000");
#define     __SPRINTF_REPLACEMENT_005__     sprintf(&message[__message_index__], "0");
#define     __SPRINTF_REPLACEMENT_006__     sprintf(&message[__message_index__], "%c", va_arg(__va_args__, int));
#define     __SPRINTF_REPLACEMENT_007__     sprintf(&message[__message_index__], "%d", va_arg(__va_args__, int));
#define     __SPRINTF_REPLACEMENT_008__     sprintf(&message[__message_index__], "%u", va_arg(__va_args__, unsigned int));
#define     __SPRINTF_REPLACEMENT_009__     sprintf(&message[__message_index__], "%x", va_arg(__va_args__, unsigned int));
#define     __SPRINTF_REPLACEMENT_010__     sprintf(&message[__message_index__], "%X", va_arg(__va_args__, unsigned int));




#endif

#define FORMAT_STR_TO_MESSAGE_VARIABLE()                                                     \
                                                                                             \
                char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];                             \
                                                                                             \
                for (int __i__ = 0;                                                          \
                     __i__ < LOGGER_MESSAGE_STRING_BUFFER_SIZE;                              \
                     __i__++) {                                                              \
                                                                                             \
                  message[__i__] = 0;                                                        \
                }                                                                            \
                                                                                             \
                va_list __va_args__;                                                         \
                va_start(__va_args__, format_str);                                           \
                                                                                             \
                int __message_index__ = 0;                                                   \
                char __identifier_char__;                                                    \
                char __identifier_modifier__;                                                \
                                                                                             \
                int __temp_index__;                                                          \
                int __temp_count__;                                                          \
                char __temp_char__;                                                          \
                unsigned int __temp_uint__;                                                  \
                                                                                             \
                for (int __format_str_index__ = 0;                                           \
                     __format_str_index__ < (int)strlen(format_str);                         \
                     __format_str_index__++) {                                               \
                                                                                             \
                  __identifier_char__ = format_str[__format_str_index__ + 1];                \
                  __identifier_modifier__ = -1;                                              \
                                                                                             \
                  if ((__identifier_char__ == '0' ||                                         \
                       __identifier_char__ == '1' ||                                         \
                       __identifier_char__ == '2' ||                                         \
                       __identifier_char__ == '3' ||                                         \
                       __identifier_char__ == '4') &&                                        \
                       (__format_str_index__ + 1 < (int)strlen(format_str))) {               \
                                                                                             \
                    __identifier_modifier__ = format_str[__format_str_index__ + 2];          \
                                                                                             \
                    if (__identifier_modifier__ == 'b' ||                                    \
                        __identifier_modifier__ == 'B') {                                    \
                                                                                             \
                      __temp_char__ = __identifier_modifier__;                               \
                      __identifier_modifier__ = __identifier_char__ - 48;                    \
                      __identifier_char__ = __temp_char__;                                   \
                    }                                                                        \
                    else {                                                                   \
                      __identifier_modifier__ = -1;                                          \
                    }                                                                        \
                  }                                                                          \
                                                                                             \
                  if (format_str[__format_str_index__] != '%') {                             \
                                                                                             \
                    message[__message_index__++] = format_str[__format_str_index__];         \
                                                                                             \
                  }                                                                          \
                  else {                                                                     \
                                                                                             \
                    switch (__identifier_char__) {                                           \
                                                                                             \
                    case 'b':                                                                \
                    case 'B':                                                                \
                      __temp_uint__ = va_arg(__va_args__, unsigned int);                     \
                      __temp_index__ = __message_index__;                                    \
                      __temp_count__ = 0;                                                    \
                                                                                             \
                      while (__temp_uint__) {                                                \
                        message[__temp_index__++] = 48 + (__temp_uint__ % 2);                \
                        message[__temp_index__] = 0;                                         \
                                                                                             \
                        __temp_uint__ /= 2;                                                  \
                        __temp_count__++;                                                    \
                      }                                                                      \
                                                                                             \
                      if (__temp_index__ == __message_index__) {                             \
                                                                                             \
                        /* Value is zero */                                                  \
                        switch (__identifier_modifier__) {                                   \
                        case 0:                                                              \
                        case 1:    __SPRINTF_REPLACEMENT_001__   break;                      \
                        case 2:    __SPRINTF_REPLACEMENT_002__   break;                      \
                        case 3:    __SPRINTF_REPLACEMENT_003__   break;                      \
                        case 4:    __SPRINTF_REPLACEMENT_004__   break;                      \
                        default:   __SPRINTF_REPLACEMENT_005__   break;                      \
                        }                                                                    \
                                                                                             \
                      }                                                                      \
                      else {                                                                 \
                                                                                             \
                        /* Fill zeros if required */                                         \
                        if (__identifier_modifier__ >= 0 &&                                  \
                            __identifier_modifier__ <= 4) {                                  \
                                                                                             \
                          if (__identifier_modifier__ == 0) {                                \
                                                                                             \
                            while (__identifier_modifier__ * 8 < __temp_count__)             \
                               __identifier_modifier__++;                                    \
                          }                                                                  \
                                                                                             \
                          while (__temp_count__ < __identifier_modifier__ * 8) {             \
                            message[__temp_index__++] = 48;                                  \
                            message[__temp_index__] = 0;                                     \
                                                                                             \
                            __temp_count__++;                                                \
                          }                                                                  \
                        }                                                                    \
                                                                                             \
                        /* Reverse the order */                                              \
                        __temp_index__--;                                                    \
                        while (__temp_index__ > __message_index__) {                         \
                          __temp_char__ = message[__message_index__];                        \
                          message[__message_index__] = message[__temp_index__];              \
                          message[__temp_index__] = __temp_char__;                           \
                                                                                             \
                          __message_index__++;                                               \
                          __temp_index__--;                                                  \
                        }                                                                    \
                      }                                                                      \
                                                                                             \
                      if (__identifier_modifier__ >= 0 &&                                    \
                          __identifier_modifier__ <= 4) {                                    \
                        __format_str_index__++; /* Extra addition */                         \
                      }                                                                      \
                                                                                             \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    case 'c':                                                                \
                    case 'C':                                                                \
                      __SPRINTF_REPLACEMENT_006__                                            \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    case 'd':                                                                \
                    case 'D':                                                                \
                      __SPRINTF_REPLACEMENT_007__                                            \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    case 'u':                                                                \
                    case 'U':                                                                \
                      __SPRINTF_REPLACEMENT_008__                                            \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    case 'x':                                                                \
                      __SPRINTF_REPLACEMENT_009__                                            \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    case 'X':                                                                \
                      __SPRINTF_REPLACEMENT_010__                                            \
                      __message_index__ = (int)strlen(message);                              \
                      __format_str_index__++;                                                \
                      break;                                                                 \
                                                                                             \
                    default:                                                                 \
                      message[__message_index__++] = format_str[__format_str_index__];       \
                      break;                                                                 \
                    }                                                                        \
                  }                                                                          \
                }                                                                            \
                                                                                             \
                va_end(__va_args__);








#endif
