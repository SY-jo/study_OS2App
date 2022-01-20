#include <iostream>

namespace A
{
    void Test(void);
    void Hi(void);

    namespace AA
    {
        extern int sVal;
    }

    namespace BB
    {
        extern int sVal;
    }
}

namespace B
{
    void Test(void);
}


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
