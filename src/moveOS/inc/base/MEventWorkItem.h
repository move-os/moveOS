#ifndef _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_
#define _MOVE_OS_INC_BASE_M_EVENT_WORK_ITEM_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace base
  {

    /*********************************************************************************/
    /*                                                                               */
    /* Event's working without data                                                  */
    /*                                                                               */
    /*********************************************************************************/

    class MSimplestEventWorkItem
    {
    public:
      MSimplestEventWorkItem(simplest_func workFunc);
      void executeChain();



    protected:
      simplest_func workFunc;
      MSimplestEventWorkItem* nextWorkItem;

      friend class Event;
    };


    /*********************************************************************************/
    /*                                                                               */
    /* Events working with data                                                      */
    /*                                                                               */
    /*********************************************************************************/

    class MEventWorkItemReturn
    {
    public:
      enum {
        KEEP_CHAINING,
        BREAK_FURTHER_CHAIN
      };
    };



    class MSimpleEventWorkItem
    {
    public:
      MSimpleEventWorkItem(code_ret_simple_func workFunc);
      void executeChain();



    protected:
      code_ret_simple_func workFunc;
      MSimpleEventWorkItem* nextWorkItem;

      friend class Event;
    };

  }
}



#endif
