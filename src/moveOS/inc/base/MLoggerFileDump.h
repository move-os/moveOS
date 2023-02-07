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
      void logInfo(const char* message) override;
      void logWarning(const char* message) override;
      void logError(const char* message) override;


    private:
      const char* filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS
      std::ofstream outFileStream;
#endif

    };

  }
}



#endif

