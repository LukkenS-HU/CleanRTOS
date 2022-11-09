set(srcs "src/CleanRTOS.h"
         "src/crt_CleanRTOS.h"
         "src/crt_Config.h"
         "src/crt_Flag.h"
         "src/crt_Handler.h"
         "src/crt_IHandler.h"
         "src/crt_IHandlerListener.h"
         "src/crt_ILogger.h"
         "src/crt_LoggerTask.h"
         "src/crt_MainInits.h"
         "src/crt_Mutex.h"
         "src/crt_MutexSection.h"
         "src/crt_Pool.h"
         "src/crt_Queue.h"
         "src/crt_Task.h"
         "src/crt_Timer.h"
         "src/crt_HWTimer.h"
         "src/crt_Waitable.h"
         "src/internals/crt__std_Stack.h"
         "src/internals/crt_FreeRTOS.h"
         "src/internals/crt_SimpleMutex.h"
         "src/internals/crt_TaskCriticalSection.h")

idf_component_register(SRCS ${srcs}
        INCLUDE_DIRS src
        REQUIRES driver
        )
