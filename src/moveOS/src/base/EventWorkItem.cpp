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
