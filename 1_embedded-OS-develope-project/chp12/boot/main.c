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
    Kernel_msgQ_init();

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
    uint8_t cmdBuf[16];
    uint32_t cmdBufIdx = 0;
    uint8_t uartch = 0;

    while(true)
    {
        KernelEventFlag_t handle_event = Kernel_wait_events(KernelEventFlag_UartIn | KernelEventFlag_CmdOut);
        switch(handle_event)
        {
            case KernelEventFlag_UartIn:
                Kernel_recv_msg(KernelMsgQ_Task0, &uartch, 1);
                if(uartch == '\r')
                {
                    cmdBuf[cmdBufIdx] = '\0';

                    Kernel_send_msg(KernelMsgQ_Task1, &cmdBufIdx, 1);
                    Kernel_send_msg(KernelMsgQ_Task1, cmdBuf, cmdBufIdx);
                    Kernel_send_events(KernelEventFlag_CmdIn);

                    cmdBufIdx = 0;
                }
                else
                {
                    cmdBuf[cmdBufIdx] = uartch;
                    cmdBufIdx++;
                    cmdBufIdx %= 16;
                }
                break;
            case KernelEventFlag_CmdOut:
                debug_printf("CmdOut event handled by Task 0\n");
                break;
        }
        Kernel_yield();
    }
}

void User_task1(void)
{
    uint8_t cmdlen = 0;
    uint8_t cmd[16] = {0, };

    while(true)
    {
        KernelEventFlag_t handle_event = Kernel_wait_events(KernelEventFlag_CmdIn);
        switch(handle_event)
        {
            case KernelEventFlag_CmdIn:
                memclr(cmd, 16);
                Kernel_recv_msg(KernelMsgQ_Task1, &cmdlen, 1);
                Kernel_recv_msg(KernelMsgQ_Task1, cmd, cmdlen);
                debug_printf("\nRecv Cmd: %s \n", cmd);
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