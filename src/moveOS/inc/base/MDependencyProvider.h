#ifndef _MOVE_OS_INC_BASE_M_DEPENDENCY_PROVIDER_H_
#define _MOVE_OS_INC_BASE_M_DEPENDENCY_PROVIDER_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace base
  {

    class MDependencyProvider
    {
    public:

      static MLogger* getLogger();
    };

  }
}



#endif
