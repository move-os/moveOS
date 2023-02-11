#ifndef _MOVE_OS_INC_BASE_M_LOGGER_SPLIT_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_SPLIT_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace base
  {

    class MLoggerSplit : public MLogger
    {
    public:
      MLoggerSplit(MLogger*, MLogger*);
      MLoggerSplit(MLogger*, MLogger*, MLogger*);
      MLoggerSplit(MLogger*, MLogger*, MLogger*, MLogger*);

      void log(log_level, const char* message) override;
      void logInfo(const char* format_str, ...) override;
      void logWarning(const char* format_str, ...) override;
      void logError(const char* format_str, ...) override;

      void logNoEndline(log_level, const char* message) override;
      void logInfoNoEndline(const char* format_str, ...) override;
      void logWarningNoEndline(const char* format_str, ...) override;
      void logErrorNoEndline(const char* format_str, ...) override;

    private:
      MLogger* logger_01;
      MLogger* logger_02;
      MLogger* logger_03;
      MLogger* logger_04;
    };

  }
}



#endif


