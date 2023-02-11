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

void moveOS::base::MLoggerSplit::logInfo(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

  if (logger_01 != nullptr) logger_01->logInfo(message);
  if (logger_02 != nullptr) logger_02->logInfo(message);
  if (logger_03 != nullptr) logger_03->logInfo(message);
  if (logger_04 != nullptr) logger_04->logInfo(message);
}

void moveOS::base::MLoggerSplit::logWarning(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

  if (logger_01 != nullptr) logger_01->logWarning(message);
  if (logger_02 != nullptr) logger_02->logWarning(message);
  if (logger_03 != nullptr) logger_03->logWarning(message);
  if (logger_04 != nullptr) logger_04->logWarning(message);
}

void moveOS::base::MLoggerSplit::logError(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

  if (logger_01 != nullptr) logger_01->logError(message);
  if (logger_02 != nullptr) logger_02->logError(message);
  if (logger_03 != nullptr) logger_03->logError(message);
  if (logger_04 != nullptr) logger_04->logError(message);
}

void moveOS::base::MLoggerSplit::logNoEndline(log_level logLevel, const char* message)
{
	if (logger_01 != nullptr) logger_01->logNoEndline(logLevel, message);
	if (logger_02 != nullptr) logger_02->logNoEndline(logLevel, message);
	if (logger_03 != nullptr) logger_03->logNoEndline(logLevel, message);
	if (logger_04 != nullptr) logger_04->logNoEndline(logLevel, message);
}

void moveOS::base::MLoggerSplit::logInfoNoEndline(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

	if (logger_01 != nullptr) logger_01->logInfoNoEndline(message);
	if (logger_02 != nullptr) logger_02->logInfoNoEndline(message);
	if (logger_03 != nullptr) logger_03->logInfoNoEndline(message);
	if (logger_04 != nullptr) logger_04->logInfoNoEndline(message);
}

void moveOS::base::MLoggerSplit::logWarningNoEndline(const char* format_str, ...)
{
	__FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

	if (logger_01 != nullptr) logger_01->logWarningNoEndline(message);
	if (logger_02 != nullptr) logger_02->logWarningNoEndline(message);
	if (logger_03 != nullptr) logger_03->logWarningNoEndline(message);
	if (logger_04 != nullptr) logger_04->logWarningNoEndline(message);
}

void moveOS::base::MLoggerSplit::logErrorNoEndline(const char* format_str, ...)
{
  __FORMAT_STR_TO_MESSAGE_CONVERSION(format_str, message);

	if (logger_01 != nullptr) logger_01->logErrorNoEndline(message);
	if (logger_02 != nullptr) logger_02->logErrorNoEndline(message);
	if (logger_03 != nullptr) logger_03->logErrorNoEndline(message);
	if (logger_04 != nullptr) logger_04->logErrorNoEndline(message);
}