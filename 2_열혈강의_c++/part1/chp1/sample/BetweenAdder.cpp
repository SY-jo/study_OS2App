#include <iostream>

int main(void)
{
    int val1, val2;
    std::cout << "Input 2 integer :";
    std::cin >> val1 >> val2;

    int result = 0;
    if(val1 > val2)
        val1, val2 = val2, val1; // c++ 버전에 따라서 되기도 하고 안 되기도 하고?
    for(int i = val1 + 1; i < val2; i++)
        result += i;

    std::cout << "Result = " << result << std::endl;

    return 0;
    
}