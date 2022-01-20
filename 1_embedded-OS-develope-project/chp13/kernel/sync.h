#ifndef KERNEL_SYNC_H_
#define KERNEL_SYNC_H_

#define DEF_SEM_MAX 8

void Kernel_sem_init(int32_t max);
bool Kernel_sem_test(void);
void Kernel_sem_realease(void);


#endif /* KERNEL_SYNC_H_ */