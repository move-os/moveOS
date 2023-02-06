#include "inc/base/MLoggerFileDump.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename)
{
}

moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename, log_level minimumLogLevel)
{
}

void moveOS::base::MLoggerFileDump::log(log_level logLevel, const char* message)
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

void moveOS::base::MLoggerFileDump::logInfo(const char* message)
{
}

void moveOS::base::MLoggerFileDump::logWarning(const char* message)
{
}

void moveOS::base::MLoggerFileDump::logError(const char* message)
{
}
