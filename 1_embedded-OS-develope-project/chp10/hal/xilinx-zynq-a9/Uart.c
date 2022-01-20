#include "stdint.h"
#include "Uart.h"
#include "../HalUart.h"

extern volatile uint32_t* uart;

void bit_on(uint32_t* reg, uint32_t bit)
{
    uint32_t temp = *reg | bit;
    *reg = temp;
}

uint8_t bit_val(uint32_t* reg, uint32_t bit)
{
    uint8_t temp = (*reg & bit) == bit;
    return temp;
}

void Hal_uart_init(void)
{
    volatile uint32_t *cr = XUARTPS_BASE_ADDRESS0 + XUARTPS_CR_OFFSET;
    bit_on(cr, XUARTPS_CR_RX_EN);
    bit_on(cr, XUARTPS_CR_TX_EN);
}

void Hal_uart_put_char(uint8_t ch)
{
    //volatile uint32_t *sr = uart + XUARTPS_SR_OFFSET;
    volatile uint32_t *sr = 0xE000002C;

    uint32_t *temp = 0xE0000030;
    while(!bit_val(sr, XUARTPS_SR_TXEMPTY));
        *temp = (ch & 0xFF);
        // *(uart + XUARTPS_FIFO_OFFSET) = (ch & 0xFF);
}