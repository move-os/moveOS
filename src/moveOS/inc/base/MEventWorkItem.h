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
    /* Event's without data                                                          */
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
