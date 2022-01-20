#include "stdint.h"
#include "stdbool.h"

#include "stdio.h"
#include "stdlib.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"

#include "task.h"
#include "event.h"
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
    Kernel_event_flag_init();

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
    while(true)
    {
        KernelEventFlag_t handle_event = Kernel_wait_events(KernelEventFlag_UartIn | KernelEventFlag_CmdOut);
        switch(handle_event)
        {
            case KernelEventFlag_UartIn:
                debug_printf("Event Handled by Task 0 \n");
                 break;
            case KernelEventFlag_CmdOut:
                debug_printf("CmdOut event handled by Task 0\n");
        }
        Kernel_yield();
    }
}

void User_task1(void)
{
    while(true)
    {
        KernelEventFlag_t handle_event = Kernel_wait_events(KernelEventFlag_CmdIn);
        switch(handle_event)
        {
            case KernelEventFlag_CmdIn:
                debug_printf("Event Handled by Task 1 \n");
                break;
        }
        Kernel_yield();
    }
}

void User_task2(void)
{
    while(true)
    {
        Kernel_yield();
    }
}