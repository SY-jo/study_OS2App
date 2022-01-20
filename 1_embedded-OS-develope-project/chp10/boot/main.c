#include "stdint.h"
#include "stdbool.h"

#include "stdio.h"
#include "stdlib.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"

#include "task.h"
#include "Kernel.h"

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
    debug_printf("% operation \n");
    int j = 0;
    for(int i = 0; i < 20; i++)
    {
        debug_printf("j : %u \n", j);
        j++;
        j %= 3;
    }

    while(1);
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

    Kernel_start();
}

void User_task0(void)
{
    for(int i = 0; i < 10; i++)
        debug_printf("User Task #0\n");
    Kernel_yield();

    while(true);
}

void User_task1(void)
{
    for(int i = 0; i < 10; i++)
        debug_printf("User Task #1\n");
    Kernel_yield();

    while(true);

}

void User_task2(void)
{
    for(int i = 0; i < 10; i++)
        debug_printf("User Task #2\n");
    Kernel_yield();

    while(true);

}