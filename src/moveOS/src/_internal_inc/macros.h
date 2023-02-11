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


#define FORMAT_STR_TO_MESSAGE_VARIABLE(fmt_var, msg_var)           char msg_var[LOGGER_MESSAGE_STRING_BUFFER_SIZE];                                                           \
                                                                                                                                                                              \
                                                                   for (int __i__ = 0; __i__ < LOGGER_MESSAGE_STRING_BUFFER_SIZE; __i__++) { msg_var[__i__] = 0; }            \
                                                                                                                                                                              \
                                                                   va_list __va_args__;                                                                                       \
                                                                   va_start(__va_args__, format_str);                                                                         \
                                                                                                                                                                              \
                                                                   int __msg_var_index__ = 0;                                                                                 \
                                                                   char __identifier_char__;                                                                                  \
                                                                   char __identifier_modifier__;                                                                              \
                                                                                                                                                                              \
                                                                   int __temp_index__;                                                                                        \
                                                                   int __temp_count__;                                                                                        \
                                                                   char __temp_char__;                                                                                        \
                                                                   unsigned int __temp_uint__;                                                                                \
                                                                                                                                                                              \
                                                                   for (int __format_str_index = 0; __format_str_index < strlen(format_str); __format_str_index++) {          \
                                                                                                                                                                              \
                                                                     __identifier_char__ = format_str[__format_str_index + 1];                                                \
                                                                     __identifier_modifier__ = -1;                                                                            \
                                                                                                                                                                              \
                                                                   	  if ((__identifier_char__ == '0' ||                                                                      \
                                                                   		     __identifier_char__ == '1' ||                                                                      \
                                                                   		     __identifier_char__ == '2' ||                                                                      \
                                                                   		     __identifier_char__ == '3' ||                                                                      \
                                                                   		     __identifier_char__ == '4') && (__format_str_index + 1 < strlen(format_str))) {                    \
                                                                                                                                                                              \
                                                                   		  __identifier_modifier__ = format_str[__format_str_index + 2];                                         \
                                                                                                                                                                              \
                                                                   		  if (__identifier_modifier__ == 'b' || __identifier_modifier__ == 'B') {                               \
                                                                   		  	__temp_char__ = __identifier_modifier__;                                                            \
                                                                   		  	__identifier_modifier__ = __identifier_char__ - 48;                                                 \
                                                                   		  	__identifier_char__ = __temp_char__;                                                                \
                                                                   		  }                                                                                                     \
                                                                   		  else {                                                                                                \
                                                                   		  	__identifier_modifier__ = -1;                                                                       \
                                                                   		  }                                                                                                     \
                                                                   	  }                                                                                                       \
                                                                                                                                                                              \
                                                                   	  if (format_str[__format_str_index] != '%') {                                                            \
                                                                                                                                                                              \
                                                                   		  msg_var[__msg_var_index__++] = format_str[__format_str_index];                                        \
                                                                                                                                                                              \
                                                                   	  }                                                                                                       \
                                                                   	  else {                                                                                                  \
                                                                                                                                                                              \
                                                                   		  switch (__identifier_char__) {                                                                        \
                                                                                                                                                                              \
                                                                   		  case 'b':                                                                                             \
                                                                   		  case 'B':                                                                                             \
                                                                   		  	__temp_uint__ = va_arg(__va_args__, unsigned int);                                                  \
                                                                   		  	__temp_index__ = __msg_var_index__;                                                                 \
                                                                   		  	__temp_count__ = 0;                                                                                 \
                                                                                                                                                                              \
                                                                   		  	while (__temp_uint__) {                                                                             \
                                                                   		  		msg_var[__temp_index__++] = 48 + (__temp_uint__ % 2);                                             \
                                                                   		  		msg_var[__temp_index__] = 0;                                                                      \
                                                                                                                                                                              \
                                                                   		  		__temp_uint__ /= 2;                                                                               \
                                                                   		  		__temp_count__++;                                                                                 \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	if (__temp_index__ == __msg_var_index__) {                                                          \
                                                                                                                                                                              \
                                                                   		  		/* Value is zero */                                                                               \
                                                                   		  		switch (__identifier_modifier__) {                                                                \
                                                                   		  		case 0:                                                                                           \
                                                                   		  		case 1:  sprintf(&msg_var[__msg_var_index__], "00000000");                         break;         \
                                                                   		  		case 2:  sprintf(&msg_var[__msg_var_index__], "0000000000000000");                 break;         \
                                                                   		  		case 3:	 sprintf(&msg_var[__msg_var_index__], "000000000000000000000000");         break;         \
                                                                   		  		case 4:  sprintf(&msg_var[__msg_var_index__], "00000000000000000000000000000000"); break;         \
                                                                   		  		default: sprintf(&msg_var[__msg_var_index__], "0"); break;                                        \
                                                                   		  		}                                                                                                 \
                                                                                                                                                                              \
                                                                   		  	}                                                                                                   \
                                                                   		  	else {                                                                                              \
                                                                                                                                                                              \
                                                                   		  		/* Fill zeros if required */                                                                      \
                                                                   		  		if (__identifier_modifier__ >= 0 && __identifier_modifier__ <= 4) {                               \
                                                                   		  			if (__identifier_modifier__ == 0) {                                                             \
                                                                   		  				while (__identifier_modifier__ * 8 < __temp_count__) __identifier_modifier__++;               \
                                                                   		  			}                                                                                               \
                                                                                                                                                                              \
                                                                   		  			while (__temp_count__ < __identifier_modifier__ * 8) {                                          \
                                                                   		  				msg_var[__temp_index__++] = 48;                                                               \
                                                                   		  				msg_var[__temp_index__] = 0;                                                                  \
                                                                                                                                                                              \
                                                                   		  				__temp_count__++;                                                                             \
                                                                   		  			}                                                                                               \
                                                                   		  		}                                                                                                 \
                                                                                                                                                                              \
                                                                   		  		/* Reverse the order */                                                                           \
                                                                   		  		__temp_index__--;                                                                                 \
                                                                   		  		while (__temp_index__ > __msg_var_index__) {                                                      \
                                                                   		  			__temp_char__ = msg_var[__msg_var_index__];                                                     \
                                                                   		  			msg_var[__msg_var_index__] = msg_var[__temp_index__];                                           \
                                                                   		  			msg_var[__temp_index__] = __temp_char__;                                                        \
                                                                                                                                                                              \
                                                                   		  			__msg_var_index__++;                                                                            \
                                                                   		  			__temp_index__--;                                                                               \
                                                                   		  		}                                                                                                 \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	if (__identifier_modifier__ >= 0 && __identifier_modifier__ <= 4) {                                 \
                                                                   		  		__format_str_index++; /* Extra addition */                                                        \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'c':                                                                                             \
                                                                   		  case 'C':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index__], "%c", va_arg(__va_args__, int));                               \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'd':                                                                                             \
                                                                   		  case 'D':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index__], "%d", va_arg(__va_args__, int));                               \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'u':                                                                                             \
                                                                   		  case 'U':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index__], "%u", va_arg(__va_args__, unsigned int));                      \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'x':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index__], "%x", va_arg(__va_args__, unsigned int));                      \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'X':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index__], "%X", va_arg(__va_args__, unsigned int));                      \
                                                                   		  	__msg_var_index__ = strlen(msg_var);                                                                \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  default:                                                                                              \
                                                                   		  	msg_var[__msg_var_index__++] = format_str[__format_str_index];                                      \
                                                                   		  	break;                                                                                              \
                                                                   		  }                                                                                                     \
                                                                   	  }                                                                                                       \
                                                                   }                                                                                                          \
                                                                                                                                                                              \
                                                                   va_end(__va_args__);








#endif
