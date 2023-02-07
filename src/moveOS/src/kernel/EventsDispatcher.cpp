#include "inc/kernel/MEventsDispatcher.h"

#include "src/_internal_inc/macros.h"

#include "inc/base/MObjectProvider.h"
#include "inc/base/MLogger.h"


moveOS::kernel::MEventsDispatcher::MEventsDispatcher(moveOS::base::MLogger* logger)
{
  this->logger = logger;
}
