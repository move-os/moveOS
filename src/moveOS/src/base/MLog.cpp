#include "inc/base/MLog.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLog::MLog()
{
  minimumLogLevel = LOG_INFO;
}

moveOS::base::MLog::MLog(log_level logLevel)
{
  minimumLogLevel = logLevel;
}

void moveOS::base::MLog::setMinimumLogLevel(log_level logLevel)
{
  minimumLogLevel = logLevel;
}
