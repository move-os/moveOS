#include "inc/base/MLogger.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLogger::MLogger()
{
  minimumLogLevel = LOG_INFO;
}

moveOS::base::MLogger::MLogger(log_level logLevel)
{
  minimumLogLevel = logLevel;
}

void moveOS::base::MLogger::setMinimumLogLevel(log_level logLevel)
{
  minimumLogLevel = logLevel;
}
