#ifndef _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_
#define _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_

#include "_types.h"
#include "_config.h"


#define STR_RTRIM(x) {uint16 __inr_=0;while(x[__inr_]!=' ' && x[__inr_]!='\0')__inr_++;x[__inr_]='\0';}
#define STR_LTRIM(x) {uint16 __nsl_=0,__inl_=0;while(x[__nsl_]==' ')__nsl_++;while(x[__nsl_]!='\0'){x[__inl_]=x[__nsl_];__inl_++;__nsl_++;}x[__inl_]='\0';}
#define STR_TRIM(x) STR_LTRIM(x) STR_RTRIM(x)

#define __FORMAT_STR_TO_MESSAGE_CONVERSION(fmt_var, msg_var)       char msg_var[LOGGER_MESSAGE_STRING_BUFFER_SIZE];                                               \
                                                                                                                                                                  \
                                                                   for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { msg_var[_i] = 0; }            \
                                                                                                                                                                  \
                                                                   va_list va_args;                                                                               \
                                                                   va_start(va_args, format_str);                                                                 \
                                                                                                                                                                  \
                                                                   int msg_var_index = 0;                                                                         \
                                                                   char identifier_char;                                                                          \
                                                                   char identifier_modifier;                                                                      \
                                                                                                                                                                  \
                                                                   int __temp_index;                                                                              \
                                                                   int __temp_count;                                                                              \
                                                                   char __temp_char;                                                                              \
                                                                   unsigned int __temp_uint;                                                                      \
                                                                                                                                                                  \
                                                                   for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {    \
                                                                                                                                                                  \
                                                                     identifier_char = format_str[format_str_index + 1];                                          \
                                                                     identifier_modifier = -1;                                                                    \
                                                                                                                                                                  \
                                                                   	  if ((identifier_char == '0' ||                                                              \
                                                                   		     identifier_char == '1' ||                                                              \
                                                                   		     identifier_char == '2' ||                                                              \
                                                                   		     identifier_char == '3' ||                                                              \
                                                                   		     identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {              \
                                                                                                                                                                  \
                                                                   		  identifier_modifier = format_str[format_str_index + 2];                                   \
                                                                                                                                                                  \
                                                                   		  if (identifier_modifier == 'b' || identifier_modifier == 'B') {                           \
                                                                   		  	__temp_char = identifier_modifier;                                                      \
                                                                   		  	identifier_modifier = identifier_char - 48;                                             \
                                                                   		  	identifier_char = __temp_char;                                                          \
                                                                   		  }                                                                                         \
                                                                   		  else {                                                                                    \
                                                                   		  	identifier_modifier = -1;                                                               \
                                                                   		  }                                                                                         \
                                                                   	  }                                                                                           \
                                                                                                                                                                  \
                                                                   	  if (format_str[format_str_index] != '%') {                                                  \
                                                                                                                                                                  \
                                                                   		  msg_var[msg_var_index++] = format_str[format_str_index];                                  \
                                                                                                                                                                  \
                                                                   	  }                                                                                           \
                                                                   	  else {                                                                                      \
                                                                                                                                                                  \
                                                                   		switch (identifier_char) {                                                                  \
                                                                                                                                                                  \
                                                                   		case 'b':                                                                                   \
                                                                   		case 'B':                                                                                   \
                                                                   			__temp_uint = va_arg(va_args, unsigned int);                                              \
                                                                   			__temp_index = msg_var_index;                                                             \
                                                                   			__temp_count = 0;                                                                         \
                                                                                                                                                                  \
                                                                   			while (__temp_uint) {                                                                     \
                                                                   				msg_var[__temp_index++] = 48 + (__temp_uint % 2);                                       \
                                                                   				msg_var[__temp_index] = 0;                                                              \
                                                                                                                                                                  \
                                                                   				__temp_uint /= 2;                                                                       \
                                                                   				__temp_count++;                                                                         \
                                                                   			}                                                                                         \
                                                                                                                                                                  \
                                                                   			if (__temp_index == msg_var_index) {                                                      \
                                                                                                                                                                  \
                                                                   				/* Value is zero */                                                                     \
                                                                   				switch (identifier_modifier) {                                                          \
                                                                   				case 0:                                                                                 \
                                                                   				case 1:  sprintf(&msg_var[msg_var_index], "00000000");                         break;   \
                                                                   				case 2:  sprintf(&msg_var[msg_var_index], "0000000000000000");                 break;   \
                                                                   				case 3:	 sprintf(&msg_var[msg_var_index], "000000000000000000000000");         break;   \
                                                                   				case 4:  sprintf(&msg_var[msg_var_index], "00000000000000000000000000000000"); break;   \
                                                                   				default: sprintf(&msg_var[msg_var_index], "0"); break;                                  \
                                                                   				}                                                                                       \
                                                                                                                                                                  \
                                                                   			}                                                                                         \
                                                                   			else {                                                                                    \
                                                                                                                                                                  \
                                                                   				/* Fill zeros if required */                                                            \
                                                                   				if (identifier_modifier >= 0 && identifier_modifier <= 4) {                             \
                                                                   					if (identifier_modifier == 0) {                                                       \
                                                                   						while (identifier_modifier * 8 < __temp_count) identifier_modifier++;               \
                                                                   					}                                                                                     \
                                                                                                                                                                  \
                                                                   					while (__temp_count < identifier_modifier * 8) {                                      \
                                                                   						msg_var[__temp_index++] = 48;                                                       \
                                                                   						msg_var[__temp_index] = 0;                                                          \
                                                                                                                                                                  \
                                                                   						__temp_count++;                                                                     \
                                                                   					}                                                                                     \
                                                                   				}                                                                                       \
                                                                                                                                                                  \
                                                                   				/* Reverse the order */                                                                 \
                                                                   				__temp_index--;                                                                         \
                                                                   				while (__temp_index > msg_var_index) {                                                  \
                                                                   					__temp_char = msg_var[msg_var_index];                                                 \
                                                                   					msg_var[msg_var_index] = msg_var[__temp_index];                                       \
                                                                   					msg_var[__temp_index] = __temp_char;                                                  \
                                                                                                                                                                  \
                                                                   					msg_var_index++;                                                                      \
                                                                   					__temp_index--;                                                                       \
                                                                   				}                                                                                       \
                                                                   			}                                                                                         \
                                                                                                                                                                  \
                                                                   			if (identifier_modifier >= 0 && identifier_modifier <= 4) {                               \
                                                                   				format_str_index++; /* Extra addition */                                                \
                                                                   			}                                                                                         \
                                                                                                                                                                  \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		case 'c':                                                                                   \
                                                                   		case 'C':                                                                                   \
                                                                   			sprintf(&msg_var[msg_var_index], "%c", va_arg(va_args, int));                             \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		case 'd':                                                                                   \
                                                                   		case 'D':                                                                                   \
                                                                   			sprintf(&msg_var[msg_var_index], "%d", va_arg(va_args, int));                             \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		case 'u':                                                                                   \
                                                                   		case 'U':                                                                                   \
                                                                   			sprintf(&msg_var[msg_var_index], "%u", va_arg(va_args, unsigned int));                    \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		case 'x':                                                                                   \
                                                                   			sprintf(&msg_var[msg_var_index], "%x", va_arg(va_args, unsigned int));                    \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		case 'X':                                                                                   \
                                                                   			sprintf(&msg_var[msg_var_index], "%X", va_arg(va_args, unsigned int));                    \
                                                                   			msg_var_index = strlen(msg_var);                                                          \
                                                                   			format_str_index++;                                                                       \
                                                                   			break;                                                                                    \
                                                                                                                                                                  \
                                                                   		default:                                                                                    \
                                                                   			msg_var[msg_var_index++] = format_str[format_str_index];                                  \
                                                                   			break;                                                                                    \
                                                                   		}                                                                                           \
                                                                   	}                                                                                             \
                                                                   }                                                                                              \
                                                                                                                                                                  \
                                                                   va_end(va_args);








#endif
