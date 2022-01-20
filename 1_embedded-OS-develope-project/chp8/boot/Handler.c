#include "stdbool.h"
#include "stdint.h"
#include "HalInterrupt.h"
#include "HalUart.h"

__attribute__((interrupt("IRQ"))) void Irq_Handler(void)
{
    Hal_interrupt_run_handler(); 
}

__attribute__((interrupt("FIQ"))) void Fiq_Handler(void)
{
    while(true);
}