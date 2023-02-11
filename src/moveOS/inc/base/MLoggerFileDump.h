#ifndef _MOVE_OS_INC_BASE_M_LOGGER_FILE_DUMP_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_FILE_DUMP_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS
  #include <fstream>
#endif


namespace moveOS
{
  namespace base
  {

    class MLoggerFileDump : public MLogger
    {
    public:
      MLoggerFileDump(const char* filename);
      MLoggerFileDump(const char* filename, log_level minimumLogLevel);

      void log(log_level, const char* message) override;
      void logInfo(const char* format_str, ...) override;
      void logWarning(const char* format_str, ...) override;
      void logError(const char* format_str, ...) override;

      void logNoEndline(log_level, const char* message) override;
      void logInfoNoEndline(const char* format_str, ...) override;
      void logWarningNoEndline(const char* format_str, ...) override;
      void logErrorNoEndline(const char* format_str, ...) override;


    private:
      const char* filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS
      std::ofstream outFileStream;
#endif

    };

  }
}



#endif

