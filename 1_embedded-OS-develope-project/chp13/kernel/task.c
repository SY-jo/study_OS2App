#include "stdint.h"
#include "stdbool.h"

#include "ARMv7AR.h"
#include "task.h"

static KernelTcb_t  sTask_list[MAX_TASK_NUM];
static uint32_t     sAllocated_tcb_index;
static uint32_t     sCurrent_tcb_index;

static KernelTcb_t* sCurrent_tcb;
static KernelTcb_t* sNext_tcb;

static KernelTcb_t* Scheduler_round_robin_algorithm(void);
static void Save_context(void);
static void Restore_context(void);


void Kernel_task_init(void)
{
    sAllocated_tcb_index = 0;

    for(uint32_t i = 0; i < MAX_TASK_NUM; i++)
    {
        sTask_list[i].stack_base = (uint8_t*)(TASK_STACK_START + (i * USR_TASK_STACK_SIZE));
        sTask_list[i].sp = (uint32_t)sTask_list[i].stack_base + USR_TASK_STACK_SIZE - 4;
        
        sTask_list[i].sp -= sizeof(KernelTaskContext_t);
        KernelTaskContext_t* ctx = (KernelTaskContext_t*)sTask_list[i].sp;
        ctx->pc = 0;
        ctx->spsr = ARM_MODE_BIT_SYS;
    }
}

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc)
{
    KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if(sAllocated_tcb_index > MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }

    KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
    ctx->pc = (uint32_t)startFunc;
    
    return (sAllocated_tcb_index - 1);
}

static KernelTcb_t* Scheduler_round_robin_algorithm(void)
{
    sCurrent_tcb_index++;
    sCurrent_tcb_index %= sAllocated_tcb_index; //현재 task의 index가 만들어진 task개수를 넘기지 않도록함. 한 바퀴 다 돌았으면 index 0번부터 시작

    return &sTask_list[sCurrent_tcb_index];
}

void Kernel_task_schedular(void)
{
    sCurrent_tcb = &sTask_list[sCurrent_tcb_index];
    sNext_tcb = Scheduler_round_robin_algorithm();

    Kernel_task_context_switching();    
}

__attribute__ ((naked)) void Kernel_task_context_switching(void)
{
    __asm__ ("B Save_context");
    __asm__ ("B Restore_context");
}

static __attribute__ ((naked)) void Save_context(void)
{
    //현재 task의 context를 task stack에 저장
    __asm__("PUSH {lr}");
    __asm__("PUSH {r0-r12}");
    __asm__("MRS r0, cpsr");
    __asm__("PUSH {r0}");

    //변화한 task stack pointer를 tcb에 저장. 나중에 restore 할 때를 위해.
    __asm__("LDR r0, =sCurrent_tcb");
    __asm__("LDR r0, [r0]"); // 주소를 제대로 받아오려면 이렇게 해야된다는데..
    __asm__("STMIA r0!, {sp}"); //Kernel_tcb_t 구조체의 첫 번째 멤버가 uint32_t sp 이니까 가능

}

static __attribute__ ((naked)) void Restore_context(void)
{
    // tcb 의 sp 멤버의 값을 sp register 에 load
    __asm__("LDR r0, =sNext_tcb");
    __asm__("LDR r0, [r0]"); 
    __asm__("LDMIA r0!, {sp}"); 

    // context를 register에 load
    __asm__("POP {r0}");
    __asm__("MSR cpsr, r0");
    __asm__("POP {r0-r12}");
    __asm__("POP {pc}");
}

void Kernel_task_start(void)
{
    sNext_tcb = &sTask_list[0];
    Restore_context();
}