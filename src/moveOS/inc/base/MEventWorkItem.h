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
    /* Events without data                                                           */
    /*                                                                               */
    /*     - no outputs and no inputs to/from event handler functions                */
    /*     - helpful in chaining all the functions whenever relevant event is raised */
    /*                                                                               */
    /*                                                                               */
    /*                                                                               */
    /*                                                                               */
    /*********************************************************************************/

    class MSimplestEventWorkItem
    {
    public:
      MSimplestEventWorkItem(simplest_func workFunc);
      void executeSelf();
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
    /*     - always returning code from event handler functions                      */
    /*         - helpful in chaining and breaking the call chains                    */
    /*         - return values are defined in types, i.e.,                           */
    /*             - MEventWorkItemResult::KEEP_CHAINING                             */
    /*                 - To keep chaining the calls                                  */
    /*             - MEventWorkItemResult::BREAK_FURTHER_CHAIN                       */
    /*                 - To stop the chains of further calls                         */
    /*                                                                               */
    /*     - input data can be NONE, and other types of commonly required data       */
    /*                                                                               */
    /*                                                                               */
    /*                                                                               */
    /*                                                                               */
    /*********************************************************************************/

    class MSimpleEventWorkItem
    {
    public:
      MSimpleEventWorkItem(code_ret_simple_func workFunc);
      void executeSelf();
      void executeChain();


    protected:
      code_ret_simple_func workFunc;
      MSimpleEventWorkItem* nextWorkItem;

      friend class Event;
    };





    class MDataEventWorkItem
    {
    public:
      MDataEventWorkItem(data_handler_func workFunc);
      void executeSelf(byte* data, uint16 length);
      void executeChain(byte* data, uint16 length);


    protected:
      data_handler_func workFunc;
      MDataEventWorkItem* nextWorkItem;

      friend class Event;
    };





    class MIntegralDataEventWorkItem
    {
    public:
      MIntegralDataEventWorkItem(integral_data_handler_func workFunc);
      void executeSelf(uint16 data);
      void executeChain(uint16 data);


    protected:
      integral_data_handler_func workFunc;
      MIntegralDataEventWorkItem* nextWorkItem;

      friend class Event;
    };

  }
}



#endif
