#include "inc/base/MDependencyProvider.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MLogger.h"
#include "inc/base/MLoggerBlank.h"
#include "inc/base/MLoggerConsole.h"
#include "inc/base/MLoggerFileDump.h"
#include "inc/base/MLoggerSplit.h"


static moveOS::base::MLogger* logger = nullptr;

moveOS::base::MLogger* moveOS::base::MDependencyProvider::getLogger()
{
  if (logger == nullptr)
  {
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX

    logger = new MLoggerSplit(
      new MLoggerConsole(),
      new MLoggerFileDump("log_dump.dat"));

#elif   TARGET_PLATFORM == PLATFORM_WINDOWS

    logger = new MLoggerSplit(
      new MLoggerConsole(),
      new MLoggerFileDump("log_dump.dat"));

#else

    logger = new MLoggerBlank();

#endif
  }

  return logger;
}
