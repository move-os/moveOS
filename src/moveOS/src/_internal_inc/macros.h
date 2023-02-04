#ifndef _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_
#define _MOVE_OS_SRC_INTERNAL_INC_MACROS_H_





#define STR_RTRIM(x) {size_t __inr_=0;while(x[__inr_]!=' ' && x[__inr_]!='\0')__inr_++;x[__inr_]='\0';}
#define STR_LTRIM(x) {size_t __nsl_=0,__inl_=0;while(x[__nsl_]==' ')__nsl_++;while(x[__nsl_]!='\0'){x[__inl_]=x[__nsl_];__inl_++;__nsl_++;}x[__inl_]='\0';}
#define STR_TRIM(x) STR_LTRIM(x) STR_RTRIM(x)






#endif
