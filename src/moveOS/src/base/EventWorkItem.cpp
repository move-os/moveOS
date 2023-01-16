#include "inc/base/MEventWorkItem.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MSimplestEventWorkItem::MSimplestEventWorkItem(simplest_func workFunc)
{
  this->workFunc = workFunc;
  this->nextWorkItem = nullptr;
}

void moveOS::base::MSimplestEventWorkItem::execute()
{
  if (this->workFunc != nullptr)
  {
    this->workFunc();
  }

  MSimplestEventWorkItem* nwi = this->nextWorkItem;

  while (nwi != nullptr)
  {
    nwi->execute();
    nwi = nwi->nextWorkItem;
  }
}
