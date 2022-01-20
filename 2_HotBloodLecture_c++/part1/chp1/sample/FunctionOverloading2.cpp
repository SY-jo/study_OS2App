#include <iostream>

void MyFunc(void)
{
    std::cout << "MyFunc(void)" << std::endl;
}

void MyFunc(int a = 3)
{
    std::cout << "MyFunc(int a)" << std::endl;
}

int main(void)
{
//    MyFunc();
    MyFunc(3);
}