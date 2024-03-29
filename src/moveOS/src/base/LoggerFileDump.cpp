#include "inc/base/MLoggerFileDump.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename)
  : MLogger()
{
  this->filename = filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (filename != nullptr)
  {
    outFileStream.open(filename, std::ios_base::app);
  }

  
#endif
}

moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename, log_level minimumLogLevel)
  : MLogger(minimumLogLevel)
{
  this->filename = filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (filename != nullptr)
  {
    outFileStream.open(filename, std::ios_base::app);
  }


#endif
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

void moveOS::base::MLoggerFileDump::logInfo(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (minimumLogLevel == LOG_INFO && outFileStream.is_open())
  {
		FORMAT_STR_TO_MESSAGE_VARIABLE();
    outFileStream << message << std::endl;
    outFileStream.flush();
  }


#endif
}

void moveOS::base::MLoggerFileDump::logWarning(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (minimumLogLevel != LOG_ERROR && outFileStream.is_open())
  {
		FORMAT_STR_TO_MESSAGE_VARIABLE();
    outFileStream << "Warning: " << message << std::endl;
    outFileStream.flush();
  }


#endif
}

void moveOS::base::MLoggerFileDump::logError(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (outFileStream.is_open())
  {
		FORMAT_STR_TO_MESSAGE_VARIABLE();
    outFileStream << "Error: " << message << std::endl;
    outFileStream.flush();
  }


#endif
}


void moveOS::base::MLoggerFileDump::logNoEndline(log_level logLevel, const char* message)
{
	switch (logLevel)
	{
	case LOG_INFO:
		logInfoNoEndline(message);
		break;

	case LOG_WARNING:
		logWarningNoEndline(message);
		break;

	case LOG_ERROR:
		logErrorNoEndline(message);
		break;
	}
}

void moveOS::base::MLoggerFileDump::logInfoNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (minimumLogLevel == LOG_INFO && outFileStream.is_open())
	{
		FORMAT_STR_TO_MESSAGE_VARIABLE();
		outFileStream << message;
		outFileStream.flush();
	}


#endif
}

void moveOS::base::MLoggerFileDump::logWarningNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (minimumLogLevel != LOG_ERROR && outFileStream.is_open())
	{
		FORMAT_STR_TO_MESSAGE_VARIABLE();
		outFileStream << "Warning: " << message;
		outFileStream.flush();
	}


#endif
}

void moveOS::base::MLoggerFileDump::logErrorNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (outFileStream.is_open())
	{
    FORMAT_STR_TO_MESSAGE_VARIABLE();
		outFileStream << "Error: " << message;
		outFileStream.flush();
	}


#endif
}