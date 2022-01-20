#include <iostream>
#include "ex01-4.h"

void A::Test(void)
{
    std::cout << "Test from namespace A" << std::endl;
    Hi(); // A::Test() 와 동일한 namespace 안에 있는 놈인 경우, A::Hi()로 할 필요x
}

void B::Test(void)
{
    std::cout << "Test from namespace B" << std::endl;
}

void A::Hi(void)
{
    std::cout << "Hi" << std::endl;
}
