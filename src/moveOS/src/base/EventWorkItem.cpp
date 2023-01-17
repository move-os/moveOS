#include "inc/base/MEventWorkItem.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MSimplestEventWorkItem::MSimplestEventWorkItem(simplest_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MSimplestEventWorkItem::executeChain()
{
  if (this->workFunc != nullptr)
  {
    this->workFunc();
  }

  if (this->nextWorkItem != nullptr)
  {
    this->nextWorkItem->executeChain();
  }
}





moveOS::base::MSimpleEventWorkItem::MSimpleEventWorkItem(code_ret_simple_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MSimpleEventWorkItem::executeChain()
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc() == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain();
      }
    }
  }
}





moveOS::base::MDataEventWorkItem::MDataEventWorkItem(data_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MDataEventWorkItem::executeChain(byte* data, uint16 length)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(data, length) == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(data, length);
      }
    }
  }
}





moveOS::base::MIntegralDataEventWorkItem::MIntegralDataEventWorkItem(integral_data_handler_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MIntegralDataEventWorkItem::executeChain(uint16 data)
{
  if (this->workFunc != nullptr)
  {
    if (this->workFunc(data) == MEventWorkItemResult::KEEP_CHAINING)
    {
      if (this->nextWorkItem != nullptr)
      {
        this->nextWorkItem->executeChain(data);
      }
    }
  }
}

