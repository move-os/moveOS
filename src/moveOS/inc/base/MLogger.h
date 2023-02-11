#ifndef _MOVE_OS_INC_BASE_M_LOGGER_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace base
  {

    class MLogger
    {
    public:
      void setMinimumLogLevel(log_level);

      virtual void log(log_level, const char* message) = 0;
      virtual void logInfo(const char* message, ...) = 0;
      virtual void logWarning(const char* message, ...) = 0;
      virtual void logError(const char* message, ...) = 0;

      virtual void logNoEndline(log_level, const char* message) = 0;
      virtual void logInfoNoEndline(const char* message, ...) = 0;
      virtual void logWarningNoEndline(const char* message, ...) = 0;
      virtual void logErrorNoEndline(const char* message, ...) = 0;

    protected:
      MLogger();
      MLogger(log_level);

      log_level minimumLogLevel;
    };

  }
}



#endif

