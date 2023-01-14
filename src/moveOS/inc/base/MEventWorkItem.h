#ifndef _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_
#define _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace base
  {
    
    class MEventWorkItem
    {
    public:

      MEventWorkItem(simple_func workFunc);

      virtual void execute();



    protected:

      void* funcPtr;
      MEventWorkItem* nextWorkItem;

      friend class MEvent;
    };

  }
}



#endif
