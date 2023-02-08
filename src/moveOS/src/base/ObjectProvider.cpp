#include "inc/base/MObjectProvider.h"

#include "src/_internal_inc/macros.h"

//- Loggers
#include "inc/base/MLogger.h"
#include "inc/base/MLoggerBlank.h"
#include "inc/base/MLoggerConsole.h"
#include "inc/base/MLoggerFileDump.h"
#include "inc/base/MLoggerSplit.h"

//- Kernel Objects
#include "inc/kernel/MEventsDispatcher.h"
#include "inc/kernel/MExecutionManager.h"


/**************************************************************************/
/******                                                              ******/
/******                       Local Variables                        ******/
/******                                                              ******/
/**************************************************************************/

static moveOS::base::MLogger* logger = nullptr;

static moveOS::kernel::MEventsDispatcher* events_dispatcher = nullptr;
static moveOS::kernel::MExecutionManager* execution_manager = nullptr;





/**************************************************************************/
/******                                                              ******/
/******                           Getters                            ******/
/******                                                              ******/
/**************************************************************************/

moveOS::base::MLogger* moveOS::base::MObjectProvider::getLogger()
{
  if (logger == nullptr)
  {
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX

    logger = new MLoggerSplit(
      new moveOS::base::MLoggerConsole(),
      new moveOS::base::MLoggerFileDump("log_dump.dat"));

#elif   TARGET_PLATFORM == PLATFORM_WINDOWS

    logger = new MLoggerSplit(
      new moveOS::base::MLoggerConsole(),
      new moveOS::base::MLoggerFileDump("log_dump.dat"));

#else

    logger = new moveOS::base::MLoggerBlank();

#endif
  }

  return logger;
}

moveOS::kernel::MEventsDispatcher* moveOS::base::MObjectProvider::getEventsDispatcher()
{
  if (events_dispatcher == nullptr)
  {
    events_dispatcher = new moveOS::kernel::MEventsDispatcher(
      moveOS::base::MObjectProvider::getLogger());
  }

  return events_dispatcher;
}

moveOS::kernel::MExecutionManager* moveOS::base::MObjectProvider::getExecutionManager()
{
  if (execution_manager == nullptr)
  {
    execution_manager = new moveOS::kernel::MExecutionManager(
      moveOS::base::MObjectProvider::getLogger());
  }

  return execution_manager;
}
