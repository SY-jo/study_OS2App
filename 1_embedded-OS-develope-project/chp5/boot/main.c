#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

static void Hw_init(void);

void main(void)
{
    Hw_init();

    uint32_t i = 100;
    while(i--)
    {
        Hal_uart_put_char('N');
    }
    Hal_uart_put_char('\n');    
    putstr("Hello World!\n");

    i = 10;
    while(i--)
    {
        uint8_t ch = Hal_uart_get_char();
        Hal_uart_put_char(ch);
        Hal_uart_put_char('\n');    
    }

    char *strnull = 0;
    debug_printf("Hello \n");
    debug_printf("%s is null string \n", *strnull);
    debug_printf("Hex number : %x \n", 0xA);
}

static void Hw_init(void)
{
    Hal_uart_init();
}