//
// Created by lukkens on 11/9/22.
//
// This file is licensed under the GNU GPLv3 only.

#ifndef CRT_HWTIMER_H
#define CRT_HWTIMER_H

#include "crt_Waitable.h"
#include "crt_Task.h"
#include <driver/gptimer.h>

#include <functional>
#include <utility>

namespace crt
{
    class HWTimer
    {
    public:
        typedef std::function<bool(const gptimer_alarm_event_data_t *)> Callback_t;

        explicit HWTimer(Callback_t callback, uint64_t intervalUs)
        : _callback(std::move(callback)), _timerHandle()
        {
            gptimer_config_t configuration = {
                    .clk_src = GPTIMER_CLK_SRC_DEFAULT,
                    .direction = GPTIMER_COUNT_UP,
                    .resolution_hz = 1000'000, // 1 MHz -> 1 uS resolution
            };

            gptimer_new_timer(&configuration, &_timerHandle);

            gptimer_event_callbacks_t callbackConfig = {
                    .on_alarm = &TimerCallback
            };
            gptimer_register_event_callbacks(_timerHandle, &callbackConfig, this);

            SetInterval(intervalUs);
        }

        ~HWTimer()
        {
            gptimer_stop(_timerHandle);
            gptimer_del_timer(_timerHandle);
        }

        void Start()
        {
            gptimer_enable(_timerHandle);
            gptimer_start(_timerHandle);
        }

        void Stop()
        {
            gptimer_stop(_timerHandle);
            gptimer_disable(_timerHandle);
        }

        void SetInterval(uint64_t intervalUs)
        {
            gptimer_alarm_config_t alarmConfig = {
                    .alarm_count = intervalUs,
                    .reload_count = 0xFFFFFFFFFFFFFFFF,
                    .flags = {
                            .auto_reload_on_alarm = true
                    }
            };
            gptimer_set_alarm_action(_timerHandle, &alarmConfig);
        }

    private:
        static bool TimerCallback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
        {
            auto *self = (HWTimer*)user_ctx;
            return self->_callback(edata);
        }

        Callback_t _callback;

        gptimer_handle_t _timerHandle;
    };
}

#endif //CRT_HWTIMER_H
