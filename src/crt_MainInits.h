// by Marius Versteegen, 2022

// MainInits initializes CleanRTOS.
// A MainInits object must be defined before the Tasks are started.

#ifndef CRT_MAIN_INITS
#define CRT_MAIN_INITS

#include "internals/crt_FreeRTOS.h"
#include <esp_timer.h>

namespace crt
{
    class MainInits
    {
    public:
        MainInits()
        {
            esp_timer_init();   // Allow creation and use of microsecond timers.
        }
    };
};

#endif
