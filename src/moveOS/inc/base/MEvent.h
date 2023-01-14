#ifndef _MOVE_OS_INC_BASE_M_EVENT_H_
#define _MOVE_OS_INC_BASE_M_EVENT_H_

#include "_types.h"
#include "_config.h"
#include "base/MEventWorkItem.h"


namespace moveOS
{
  namespace base
  {

    class MEvent
    {
    public:

      virtual MEvent* thenPassTo(MEventWorkItem) = 0;
    };

  }
}



#endif
