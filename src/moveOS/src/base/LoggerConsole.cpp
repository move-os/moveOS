#include "inc/base/MLoggerConsole.h"

#include "src/_internal_inc/macros.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>




#if     TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  #include <iostream>

  using namespace std;

  #define __COLOR_FG_BLACK             "\033[0;30m"
  #define __COLOR_FG_RED               "\033[0;31m"
  #define __COLOR_FG_GREEN             "\033[0;32m"
  #define __COLOR_FG_YELLOW            "\033[0;33m"
  #define __COLOR_FG_BLUE              "\033[0;34m"
  #define __COLOR_FG_MAGENTA           "\033[0;35m"
  #define __COLOR_FG_CYAN              "\033[0;36m"
  #define __COLOR_FG_WHITE             "\033[0;37m"

  #define __COLOR_FG_BLACK_BOLD        "\033[1;30m"
  #define __COLOR_FG_RED_BOLD          "\033[1;31m"
  #define __COLOR_FG_GREEN_BOLD        "\033[1;32m"
  #define __COLOR_FG_YELLOW_BOLD       "\033[1;33m"
  #define __COLOR_FG_BLUE_BOLD         "\033[1;34m"
  #define __COLOR_FG_MAGENTA_BOLD      "\033[1;35m"
  #define __COLOR_FG_CYAN_BOLD         "\033[1;36m"
  #define __COLOR_FG_WHITE_BOLD        "\033[1;37m"

  #define __COLOR_FG_BLACK_BLINK       "\033[5;30m"
  #define __COLOR_FG_RED_BLINK         "\033[5;31m"
  #define __COLOR_FG_GREEN_BLINK       "\033[5;32m"
  #define __COLOR_FG_YELLOW_BLINK      "\033[5;33m"
  #define __COLOR_FG_BLUE_BLINK        "\033[5;34m"
  #define __COLOR_FG_MAGENTA_BLINK     "\033[5;35m"
  #define __COLOR_FG_CYAN_BLINK        "\033[5;36m"
  #define __COLOR_FG_WHITE_BLINK       "\033[5;37m"

  #define __COLOR_BG_BLACK             "\033[40m"
  #define __COLOR_BG_RED               "\033[41m"
  #define __COLOR_BG_GREEN             "\033[42m"
  #define __COLOR_BG_YELLOW            "\033[43m"
  #define __COLOR_BG_BLUE              "\033[44m"
  #define __COLOR_BG_MAGENTA           "\033[45m"
  #define __COLOR_BG_CYAN              "\033[46m"
  #define __COLOR_BG_WHITE             "\033[47m"

  #define __PRINT_ERROR(msg)                cout << __COLOR_FG_RED_BOLD       \
                                                 << "Error: "                 \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE          \
                                                 << endl;

  #define __PRINT_WARNING(msg)              cout << __COLOR_FG_YELLOW_BOLD    \
                                                 << "Warning: "               \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE          \
                                                 << endl;

  #define __PRINT_INFO(msg)                 cout << __COLOR_FG_WHITE          \
                                                 << msg                       \
                                                 << endl;

  #define __PRINT_ERROR_NO_ENDLINE(msg)     cout << __COLOR_FG_RED_BOLD       \
                                                 << "Error: "                 \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE;

  #define __PRINT_WARNING_NO_ENDLINE(msg)   cout << __COLOR_FG_YELLOW_BOLD    \
                                                 << "Warning: "               \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE;

  #define __PRINT_INFO_NO_ENDLINE(msg)      cout << __COLOR_FG_WHITE          \
                                                 << msg;

#else


  #define __PRINT_ERROR(msg)
  #define __PRINT_WARNING(msg)
  #define __PRINT_INFO(msg)


#endif


moveOS::base::MLoggerConsole::MLoggerConsole() : MLogger()
{
}

moveOS::base::MLoggerConsole::MLoggerConsole(log_level minimumLogLevel) : MLogger(minimumLogLevel)
{
}

void moveOS::base::MLoggerConsole::log(log_level logLevel, const char* message)
{
  switch (logLevel)
  {
  case LOG_INFO:
    logInfo(message);
    break;

  case LOG_WARNING:
    logWarning(message);
    break;

  case LOG_ERROR:
    logError(message);
    break;
  }
}

void moveOS::base::MLoggerConsole::logInfo(const char* format_str, ...)
{
  if (minimumLogLevel == LOG_INFO)
  {
		__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
    __PRINT_INFO(message);
  }
}

void moveOS::base::MLoggerConsole::logWarning(const char* format_str, ...)
{
  if (minimumLogLevel != LOG_ERROR)
  {
		__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
    __PRINT_WARNING(message);
  }
}

void moveOS::base::MLoggerConsole::logError(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
  __PRINT_ERROR(message);
}

void moveOS::base::MLoggerConsole::logNoEndline(log_level logLevel, const char* message)
{
	switch (logLevel)
	{
	case LOG_INFO:
		logInfoNoEndline(message);
		break;

	case LOG_WARNING:
		logWarningNoEndline(message);
		break;

	case LOG_ERROR:
		logErrorNoEndline(message);
		break;
	}
}

void moveOS::base::MLoggerConsole::logInfoNoEndline(const char* format_str, ...)
{
	if (minimumLogLevel == LOG_INFO)
	{
		__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
		__PRINT_INFO_NO_ENDLINE(message);
	}
}

void moveOS::base::MLoggerConsole::logWarningNoEndline(const char* format_str, ...)
{
	if (minimumLogLevel != LOG_ERROR)
	{
		__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
		__PRINT_WARNING_NO_ENDLINE(message);
	}
}

void moveOS::base::MLoggerConsole::logErrorNoEndline(const char* format_str, ...)
{
  __FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);
	__PRINT_ERROR_NO_ENDLINE(message);
}
