#ifndef _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_
#define _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace base
  {
    
    class MSimplestEventWorkItem
    {
    public:
      MSimplestEventWorkItem(simplest_func workFunc);
      void execute();



    protected:
      simplest_func workFunc;
      MSimplestEventWorkItem* nextWorkItem;

      friend class MEvent;
    };

  }
}



#endif
