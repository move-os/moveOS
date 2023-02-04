#ifndef _MOVE_OS_INC_BASE_M_EVENT_H_
#define _MOVE_OS_INC_BASE_M_EVENT_H_

#include "_types.h"
#include "_config.h"
#include "base/MEventWorkItem.h"


namespace moveOS
{
  namespace base
  {

    /*********************************************************************************/
    /*                                                                               */
    /* Base Class for all the events.                                                */
    /*                                                                               */
    /*   execute() is invoked periodically to check for events.                      */
    /*       It is essential for events that need to be checked through polling.     */
    /*                                                                               */
    /*********************************************************************************/
    class MEvent {
    public:
      virtual void execute(single elapsedTime_sec) = 0;
    };





    class MPollingEvent : public MEvent
    {
    public:
      MPollingEvent(event_poll_func pollFunction, MByteDataEventWorkItem *firstWorkItem);
      void addNextWorkItem(MByteDataEventWorkItem *nextWorkItem);
      void execute(single elapsedTime_sec) override;


    protected:
      event_poll_func pollingFunction;
      MByteDataEventWorkItem* firstWorkItem;
    };

  }
}



#endif
