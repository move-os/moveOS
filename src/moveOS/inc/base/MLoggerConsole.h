#ifndef _MOVE_OS_INC_BASE_M_LOGGER_CONSOLE_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_CONSOLE_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace base
  {

    class MLoggerConsole : public MLogger
    {
    public:
      MLoggerConsole();
      MLoggerConsole(log_level minimumLogLevel);

      void log(log_level, const char* message) override;
      void logInfo(const char* format_str, ...) override;
      void logWarning(const char* format_str, ...) override;
      void logError(const char* format_str, ...) override;

      void logNoEndline(log_level, const char* message) override;
      void logInfoNoEndline(const char* format_str, ...) override;
      void logWarningNoEndline(const char* format_str, ...) override;
      void logErrorNoEndline(const char* format_str, ...) override;
    };

  }
}



#endif

