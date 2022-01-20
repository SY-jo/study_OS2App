#include <iostream>

namespace A
{
    void myFunc_A(void)
    {
        std::cout << "Hey" << std::endl;
    }
}

int main(void)
{
    using namespace A;

    myFunc_A();

    return 0;
    
}