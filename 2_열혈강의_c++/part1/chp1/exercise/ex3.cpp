#include <iostream>

int main(void)
{
    int num;
    
    std::cout << "구구단 몇? : ";
    std::cin >> num;

    for(int i = 1; i < 10; i++)
        std::cout << num << " x " << i << " = " << num * i << std::endl;
}