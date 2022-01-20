#include <iostream>
#include "ex01-4.h"

int A::AA::sVal = 1;
int A::BB::sVal = 2;

int main(void)
{
    A::Test();
    B::Test();

    std::cout << "sVal of AA in A: " << A::AA::sVal << std::endl;
    std::cout << "sVal of BB in A : " << A::BB::sVal << std::endl;

    return 0;
}