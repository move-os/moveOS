#include "inc/base/MLoggerBlank.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLoggerBlank::MLoggerBlank() : MLogger()
{
}

void moveOS::base::MLoggerBlank::log(log_level, const char* message)
{
}

void moveOS::base::MLoggerBlank::logInfo(const char* format_str, ...)
{
}

void moveOS::base::MLoggerBlank::logWarning(const char* format_str, ...)
{
}

void moveOS::base::MLoggerBlank::logError(const char* format_str, ...)
{
}

void moveOS::base::MLoggerBlank::logNoEndline(log_level, const char* message)
{
}

void moveOS::base::MLoggerBlank::logInfoNoEndline(const char* format_str, ...)
{
}

void moveOS::base::MLoggerBlank::logWarningNoEndline(const char* format_str, ...)
{
}

void moveOS::base::MLoggerBlank::logErrorNoEndline(const char* format_str, ...)
{
}
