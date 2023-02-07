#include "inc/kernel/MExecutionManager.h"

#include "src/_internal_inc/macros.h"


#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX
//-

#elif TARGET_PLATFORM == PLATFORM_WINDOWS
//-

#elif TARGET_PLATFORM == PLATFORM_ARDUINO
//-

#elif TARGET_PLATFORM == PLATFORM_STM32F4
//-

#else
  #error "Unknown platform"
#endif


moveOS::kernel::MExecutionManager::MExecutionManager(moveOS::base::MLogger* logger)
{
  this->logger = logger;
}