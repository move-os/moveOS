#ifndef _MOVE_OS_INC_KERNEL_M_EXECUTION_MANAGER_H_
#define _MOVE_OS_INC_KERNEL_M_EXECUTION_MANAGER_H_

#include "_types.h"
#include "_config.h"


class moveOS::base::MLogger;
class moveOS::base::MObjectProvider;

namespace moveOS
{
  namespace kernel
  {

    class MExecutionManager
    {
    public:



    private:
      MExecutionManager(moveOS::base::MLogger*);

      moveOS::base::MLogger* logger;

      friend class moveOS::base::MObjectProvider;
    };

  }
}



#endif
