#include "inc/base/MEvent.h"

#include "src/_internal_inc/macros.h"


moveOS::base::MPollingEvent::MPollingEvent(event_poll_func pollFunction, MByteDataEventWorkItem *firstWorkItem)
{
  this->pollingFunction = pollFunction;
  this->firstWorkItem = firstWorkItem;
}

void moveOS::base::MPollingEvent::addNextWorkItem(MByteDataEventWorkItem* nextWorkItem)
{
  if (firstWorkItem != nullptr && nextWorkItem != nullptr)
  {
    MByteDataEventWorkItem* n = firstWorkItem;

    while (n->nextWorkItem != nullptr)
    {
      n = n->nextWorkItem;
    }

    n->nextWorkItem = nextWorkItem;
  }
}

void moveOS::base::MPollingEvent::execute(single elapsedTime_sec)
{
  if (this->pollingFunction != nullptr && firstWorkItem != nullptr)
  {
    byte ret = this->pollingFunction();

    if (ret != -1)
    {
      firstWorkItem->executeChain(ret);
    }
  }
}

