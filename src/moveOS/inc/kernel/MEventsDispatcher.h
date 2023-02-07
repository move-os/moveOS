#ifndef _MOVE_OS_INC_KERNEL_M_EVENTS_DISPATCHER_H_
#define _MOVE_OS_INC_KERNEL_M_EVENTS_DISPATCHER_H_

#include "_types.h"
#include "_config.h"

#include "base/MObjectProvider.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace kernel
  {

    class MEventsDispatcher
    {
    public:



    private:
      MEventsDispatcher(moveOS::base::MLogger*);

      moveOS::base::MLogger* logger;

      friend class MObjectProvider;
    };

  }
}



#endif
