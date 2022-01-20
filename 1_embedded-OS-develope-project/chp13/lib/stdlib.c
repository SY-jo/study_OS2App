#include "stdint.h"
#include "stdbool.h"
#include "HalTimer.h"

void delay(uint32_t ms)
{
    uint32_t goal = Hal_timer_get_1ms_counter() + ms;

    while(goal != Hal_timer_get_1ms_counter());
}

void memclr(void* dst, uint32_t count)
{
    uint8_t* mem = (uint8_t*) dst;
    
    while(count--)
    {
        *mem++ = 0;
    }
}
