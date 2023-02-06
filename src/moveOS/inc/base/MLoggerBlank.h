#ifndef _MOVE_OS_INC_BASE_M_LOGGER_BLANK_H_
#define _MOVE_OS_INC_BASE_M_LOGGER_BLANK_H_

#include "_types.h"
#include "_config.h"
#include "base/MLogger.h"


namespace moveOS
{
  namespace base
  {

    class MLoggerBlank : public MLogger
    {
    public:
      void log(log_level, const char* message) override;
    };

  }
}



#endif

