#include "stdint.h"
#include "Uart.h"

volatile uint32_t *uart = (uint32_t*)(XUARTPS_BASE_ADDRESS0);