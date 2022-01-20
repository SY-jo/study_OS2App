#include "stdint.h"
#include "HalUart.h"
#include "HalInterrupt.h"
#include "stdio.h"

static void Hw_init(void);

void main(void)
{
    Hw_init();

    putstr("Hello World! 2\n");

    while(1);
}

void Hw_init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
}