#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"



static void Hw_init(void);

void main(void)
{
    Hw_init();

    putstr("Hello World! 2\n");

    while(1)
    {
        debug_printf("Current Timer Counter : %u \n", Hal_timer_get_1ms_counter());
        delay(1000);
    }
}

void Hw_init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
    Hal_timer_init();
}