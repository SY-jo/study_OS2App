#include "stdint.h"
#include "stdbool.h"

#include "Kernel.h"
#include "memio.h"

void Kernel_yield()
{
    Kernel_task_schedular();
}

void Kernel_start()
{
    Kernel_task_start();
}

void Kernel_send_events(uint32_t event_list)
{
    for(uint32_t i = 0; i < 32; i++)
    {
        if((event_list >> i) & 0x00000001)
        {
            KernelEventFlag_t sending_event = KernelEventFlag_Empty;
            sending_event = (KernelEventFlag_t)SET_BIT(sending_event, i); //list에서 1bit를 parsing 하고 KernelEventFlag_t type으로 casting
            
            Kernel_event_flag_set(sending_event);
        }
    }
}

KernelEventFlag_t Kernel_wait_events(uint32_t waiting_list)
{
    for(uint32_t i = 0; i < 32; i++)
    {
        if((waiting_list >> i) & 0x00000001)
        {
            KernelEventFlag_t waiting_event = KernelEventFlag_Empty;
            waiting_event = (KernelEventFlag_t)SET_BIT(waiting_event, i);
            
            if(Kernel_event_flag_check(waiting_event))
            {
                return waiting_event;
            }
        }
    }

    return KernelEventFlag_Empty;
}

bool Kernel_send_msg(KernelMsgQ_t Qname, void* data, uint32_t count)
{
    uint8_t *d = (uint8_t*) data;

    for(uint32_t i = 0; i < count; i++)
    {
        if(false == Kernel_msgQ_enqueue(Qname, *d++))
        {
            for(uint32_t j = 0; j < i; j++)
            {
                uint8_t rollback;
                Kernel_msgQ_dequeue(Qname, &rollback);
            }

            return false;
        }
    }

    return true;
}

uint32_t Kernel_recv_msg(KernelMsgQ_t Qname, void* out_data, uint32_t count)
{
    uint8_t* d = (uint8_t*)out_data;

    for(uint32_t i = 0; i < count; i++)
    {
        if(false == Kernel_msgQ_dequeue(Qname, d++))
        {
            return i;
        }
    }

    return count;
}
