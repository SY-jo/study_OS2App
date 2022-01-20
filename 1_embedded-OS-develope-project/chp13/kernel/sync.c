#include "stdbool.h"
#include "stdint.h"

#include "sync.h"

static int32_t      sSemMax;
static int32_t      sSem;

void Kernel_sem_init(int32_t max)
{
    // max 가 0 이하이거나, DEF_SEM_MAX 이상이면, sSemMax = DEF_SEM_MAX.
    sSemMax = (max <= 0) ? DEF_SEM_MAX : max;
    sSemMax = (max >= DEF_SEM_MAX) ? DEF_SEM_MAX : max; 

    sSem = sSemMax;
}

bool Kernel_sem_test(void)
{
    if(sSem <= 0)
    {
        return false;
    }

    sSem--;

    return true;
}

void Kernel_sem_realease(void)
{
    sSem++;

    if(sSem >= sSemMax)
    {
        sSem = sSemMax;
    }
}