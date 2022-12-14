// by Marius Versteegen, 2022

#ifndef CRT_INTERNAL_FREERTOS
#define CRT_INTERNAL_FREERTOS

#include <cstdio>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
//#include "esp_heap_trace.h"
#include "esp_heap_caps.h"

#endif