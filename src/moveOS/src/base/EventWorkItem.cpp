#include "inc/base/MEventWorkItem.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MEventWorkItem::MEventWorkItem(simple_func workFunc)
{
  this->funcPtr = (void*)workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MEventWorkItem::execute()
{
  if (this->funcPtr != nullptr)
  {
    ((simple_func)this->funcPtr)();
  }
}
