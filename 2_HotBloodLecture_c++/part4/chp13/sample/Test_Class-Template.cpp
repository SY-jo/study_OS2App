

#include "Test_Class-Template.h"

myClass1::myClass1(int _mem) : mem(_mem) {}

int myClass1::GetMem(void)
{
    return mem;
}

template <typename T>
myClass2<T>::myClass2(T _mem) : mem(_mem) {}

template <typename T>
T myClass2<T>::GetMem(void)
{
    return mem;
}

