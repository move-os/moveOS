#ifndef _MOVE_OS_INC_BASE_M_OBJECT_PROVIDER_H_
#define _MOVE_OS_INC_BASE_M_OBJECT_PROVIDER_H_

#include "_types.h"
#include "_config.h"

#include "base/MLogger.h"

#include "kernel/MEventsDispatcher.h"
#include "kernel/MExecutionManager.h"


namespace moveOS
{
  namespace base
  {

    class MObjectProvider
    {
    public:

      static moveOS::base::MLogger* getLogger();

      static moveOS::kernel::MEventsDispatcher* getEventsDispatcher();
      static moveOS::kernel::MExecutionManager* getExecutionManager();
    };

  }
}



#endif
