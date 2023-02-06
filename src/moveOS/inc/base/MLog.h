#ifndef _MOVE_OS_INC_BASE_M_LOG_H_
#define _MOVE_OS_INC_BASE_M_LOG_H_

#include "_types.h"
#include "_config.h"


namespace moveOS
{
  namespace base
  {

    class MLog
    {
    public:
      void setMinimumLogLevel(log_level);

      virtual void log(log_level, const char* message) = 0;

    protected:
      MLog();
      MLog(log_level);

      log_level minimumLogLevel;
    };

  }
}



#endif

