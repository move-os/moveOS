#include "inc/base/MLoggerConsole.h"

#include "src/_internal_inc/macros.h"


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
}

