#include "stdint.h"
#include "stdbool.h"

#include "stdio.h"
#include "stdlib.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"

#include "task.h"

void User_task0(void); 
void User_task1(void);
void User_task2(void);

static void Hw_init(void);
static void Kernel_init(void);

void main(void)
{
    Hw_init();
    Kernel_init();

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

void Kernel_init(void)
{
    uint32_t taskId;

    Kernel_task_init();
    
    taskId = Kernel_task_create(User_task0);
    if (taskId == NOT_ENOUGH_TASK_NUM)
    {
        putstr("Task0 creation fail \n");
    }

    taskId = Kernel_task_create(User_task1);
    if (taskId == NOT_ENOUGH_TASK_NUM)
    {
        putstr("Task1 creation fail \n");
    }

    taskId = Kernel_task_create(User_task2);
    if (taskId == NOT_ENOUGH_TASK_NUM)
    {
        putstr("Task2 creation fail \n");
    }
}

void User_task0(void)
{
    debug_printf("User Task #0\n");

    while(true);
    
}

void User_task1(void)
{
    debug_printf("User Task #0\n");

    while(true);

}

void User_task2(void)
{
    debug_printf("User Task #0\n");

    while(true);

}