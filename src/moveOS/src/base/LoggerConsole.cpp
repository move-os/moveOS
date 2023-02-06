#include "inc/base/MLoggerConsole.h"

#include "src/_internal_inc/macros.h"


#if     TARGET_PLATFORM == PLATFORM_GNU_LINUX

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

  #define __PRINT_ERROR(msg)     cout << __COLOR_FG_RED       \
                                      << "Error: "            \
                                      << __COLOR_FG_WHITE     \
                                      << msg                  \
                                      << endl;

  #define __PRINT_WARNING(msg)   cout << __COLOR_FG_YELLOW    \
                                      << "Warning: "          \
                                      << __COLOR_FG_WHITE     \
                                      << msg                  \
                                      << endl;

  #define __PRINT_INFO(msg)      cout << __COLOR_FG_WHITE     \
                                      << msg                  \
                                      << endl;

#elif   TARGET_PLATFORM == PLATFORM_WINDOWS
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

void moveOS::base::MLoggerConsole::logInfo(const char* message)
{
}

void moveOS::base::MLoggerConsole::logWarning(const char* message)
{
}

void moveOS::base::MLoggerConsole::logError(const char* message)
{
  __PRINT_ERROR(message);
}

