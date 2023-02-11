#ifndef _MOVE_OS_INC_BASE_M_LOGGER_BLANK_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_BLANK_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace base
  {

    class MLoggerBlank : public MLogger
    {
    public:
      MLoggerBlank();

      void log(log_level, const char* message) override;
      void logInfo(const char* message, ...) override;
      void logWarning(const char* message, ...) override;
      void logError(const char* message, ...) override;

      void logNoEndline(log_level, const char* message) override;
      void logInfoNoEndline(const char* message, ...) override;
      void logWarningNoEndline(const char* message, ...) override;
      void logErrorNoEndline(const char* message, ...) override;
    };

  }
}



#endif

