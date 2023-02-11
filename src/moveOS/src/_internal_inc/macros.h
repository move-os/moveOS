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
                                                                   for (int __i = 0; __i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; __i++) { msg_var[__i] = 0; }                    \
                                                                                                                                                                              \
                                                                   va_list __va_args;                                                                                         \
                                                                   va_start(__va_args, format_str);                                                                           \
                                                                                                                                                                              \
                                                                   int __msg_var_index = 0;                                                                                   \
                                                                   char __identifier_char;                                                                                    \
                                                                   char __identifier_modifier;                                                                                \
                                                                                                                                                                              \
                                                                   int __temp_index;                                                                                          \
                                                                   int __temp_count;                                                                                          \
                                                                   char __temp_char;                                                                                          \
                                                                   unsigned int __temp_uint;                                                                                  \
                                                                                                                                                                              \
                                                                   for (int __format_str_index = 0; __format_str_index < strlen(format_str); __format_str_index++) {          \
                                                                                                                                                                              \
                                                                     __identifier_char = format_str[__format_str_index + 1];                                                  \
                                                                     __identifier_modifier = -1;                                                                              \
                                                                                                                                                                              \
                                                                   	  if ((__identifier_char == '0' ||                                                                        \
                                                                   		     __identifier_char == '1' ||                                                                        \
                                                                   		     __identifier_char == '2' ||                                                                        \
                                                                   		     __identifier_char == '3' ||                                                                        \
                                                                   		     __identifier_char == '4') && (__format_str_index + 1 < strlen(format_str))) {                      \
                                                                                                                                                                              \
                                                                   		  __identifier_modifier = format_str[__format_str_index + 2];                                           \
                                                                                                                                                                              \
                                                                   		  if (__identifier_modifier == 'b' || __identifier_modifier == 'B') {                                   \
                                                                   		  	__temp_char = __identifier_modifier;                                                                \
                                                                   		  	__identifier_modifier = __identifier_char - 48;                                                     \
                                                                   		  	__identifier_char = __temp_char;                                                                    \
                                                                   		  }                                                                                                     \
                                                                   		  else {                                                                                                \
                                                                   		  	__identifier_modifier = -1;                                                                         \
                                                                   		  }                                                                                                     \
                                                                   	  }                                                                                                       \
                                                                                                                                                                              \
                                                                   	  if (format_str[__format_str_index] != '%') {                                                            \
                                                                                                                                                                              \
                                                                   		  msg_var[__msg_var_index++] = format_str[__format_str_index];                                          \
                                                                                                                                                                              \
                                                                   	  }                                                                                                       \
                                                                   	  else {                                                                                                  \
                                                                                                                                                                              \
                                                                   		  switch (__identifier_char) {                                                                          \
                                                                                                                                                                              \
                                                                   		  case 'b':                                                                                             \
                                                                   		  case 'B':                                                                                             \
                                                                   		  	__temp_uint = va_arg(__va_args, unsigned int);                                                      \
                                                                   		  	__temp_index = __msg_var_index;                                                                     \
                                                                   		  	__temp_count = 0;                                                                                   \
                                                                                                                                                                              \
                                                                   		  	while (__temp_uint) {                                                                               \
                                                                   		  		msg_var[__temp_index++] = 48 + (__temp_uint % 2);                                                 \
                                                                   		  		msg_var[__temp_index] = 0;                                                                        \
                                                                                                                                                                              \
                                                                   		  		__temp_uint /= 2;                                                                                 \
                                                                   		  		__temp_count++;                                                                                   \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	if (__temp_index == __msg_var_index) {                                                              \
                                                                                                                                                                              \
                                                                   		  		/* Value is zero */                                                                               \
                                                                   		  		switch (__identifier_modifier) {                                                                  \
                                                                   		  		case 0:                                                                                           \
                                                                   		  		case 1:  sprintf(&msg_var[__msg_var_index], "00000000");                         break;           \
                                                                   		  		case 2:  sprintf(&msg_var[__msg_var_index], "0000000000000000");                 break;           \
                                                                   		  		case 3:	 sprintf(&msg_var[__msg_var_index], "000000000000000000000000");         break;           \
                                                                   		  		case 4:  sprintf(&msg_var[__msg_var_index], "00000000000000000000000000000000"); break;           \
                                                                   		  		default: sprintf(&msg_var[__msg_var_index], "0"); break;                                          \
                                                                   		  		}                                                                                                 \
                                                                                                                                                                              \
                                                                   		  	}                                                                                                   \
                                                                   		  	else {                                                                                              \
                                                                                                                                                                              \
                                                                   		  		/* Fill zeros if required */                                                                      \
                                                                   		  		if (__identifier_modifier >= 0 && __identifier_modifier <= 4) {                                   \
                                                                   		  			if (__identifier_modifier == 0) {                                                               \
                                                                   		  				while (__identifier_modifier * 8 < __temp_count) __identifier_modifier++;                     \
                                                                   		  			}                                                                                               \
                                                                                                                                                                              \
                                                                   		  			while (__temp_count < __identifier_modifier * 8) {                                              \
                                                                   		  				msg_var[__temp_index++] = 48;                                                                 \
                                                                   		  				msg_var[__temp_index] = 0;                                                                    \
                                                                                                                                                                              \
                                                                   		  				__temp_count++;                                                                               \
                                                                   		  			}                                                                                               \
                                                                   		  		}                                                                                                 \
                                                                                                                                                                              \
                                                                   		  		/* Reverse the order */                                                                           \
                                                                   		  		__temp_index--;                                                                                   \
                                                                   		  		while (__temp_index > __msg_var_index) {                                                          \
                                                                   		  			__temp_char = msg_var[__msg_var_index];                                                         \
                                                                   		  			msg_var[__msg_var_index] = msg_var[__temp_index];                                               \
                                                                   		  			msg_var[__temp_index] = __temp_char;                                                            \
                                                                                                                                                                              \
                                                                   		  			__msg_var_index++;                                                                              \
                                                                   		  			__temp_index--;                                                                                 \
                                                                   		  		}                                                                                                 \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	if (__identifier_modifier >= 0 && __identifier_modifier <= 4) {                                     \
                                                                   		  		__format_str_index++; /* Extra addition */                                                        \
                                                                   		  	}                                                                                                   \
                                                                                                                                                                              \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'c':                                                                                             \
                                                                   		  case 'C':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index], "%c", va_arg(__va_args, int));                                   \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'd':                                                                                             \
                                                                   		  case 'D':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index], "%d", va_arg(__va_args, int));                                   \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'u':                                                                                             \
                                                                   		  case 'U':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index], "%u", va_arg(__va_args, unsigned int));                          \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'x':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index], "%x", va_arg(__va_args, unsigned int));                          \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  case 'X':                                                                                             \
                                                                   		  	sprintf(&msg_var[__msg_var_index], "%X", va_arg(__va_args, unsigned int));                          \
                                                                   		  	__msg_var_index = strlen(msg_var);                                                                  \
                                                                   		  	__format_str_index++;                                                                               \
                                                                   		  	break;                                                                                              \
                                                                                                                                                                              \
                                                                   		  default:                                                                                              \
                                                                   		  	msg_var[__msg_var_index++] = format_str[__format_str_index];                                        \
                                                                   		  	break;                                                                                              \
                                                                   		  }                                                                                                     \
                                                                   	  }                                                                                                       \
                                                                   }                                                                                                          \
                                                                                                                                                                              \
                                                                   va_end(__va_args);








#endif
