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

void moveOS::base::MLoggerSplit::log(log_level logLevel, const char* message)
{
  if (logger_01 != nullptr) logger_01->log(logLevel, message);
  if (logger_02 != nullptr) logger_02->log(logLevel, message);
  if (logger_03 != nullptr) logger_03->log(logLevel, message);
  if (logger_04 != nullptr) logger_04->log(logLevel, message);
}

void moveOS::base::MLoggerSplit::logInfo(const char* message)
{
  if (logger_01 != nullptr) logger_01->logInfo(message);
  if (logger_02 != nullptr) logger_02->logInfo(message);
  if (logger_03 != nullptr) logger_03->logInfo(message);
  if (logger_04 != nullptr) logger_04->logInfo(message);
}

void moveOS::base::MLoggerSplit::logWarning(const char* message)
{
  if (logger_01 != nullptr) logger_01->logWarning(message);
  if (logger_02 != nullptr) logger_02->logWarning(message);
  if (logger_03 != nullptr) logger_03->logWarning(message);
  if (logger_04 != nullptr) logger_04->logWarning(message);
}

void moveOS::base::MLoggerSplit::logError(const char* message)
{
  if (logger_01 != nullptr) logger_01->logError(message);
  if (logger_02 != nullptr) logger_02->logError(message);
  if (logger_03 != nullptr) logger_03->logError(message);
  if (logger_04 != nullptr) logger_04->logError(message);
}

