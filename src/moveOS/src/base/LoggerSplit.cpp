#include "inc/base/MLoggerSplit.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = nullptr;
  logger_04 = nullptr;
}

moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger,
                   MLogger* thirdLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = thirdLogger;
  logger_04 = nullptr;
}

moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger,
                   MLogger* thirdLogger,
                   MLogger* fourthLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = thirdLogger;
  logger_04 = fourthLogger;
}

void moveOS::base::MLoggerSplit::log(log_level, const char* message)
{
}

void moveOS::base::MLoggerSplit::logInfo(const char* message)
{
}

void moveOS::base::MLoggerSplit::logWarning(const char* message)
{
}

void moveOS::base::MLoggerSplit::logError(const char* message)
{
}

