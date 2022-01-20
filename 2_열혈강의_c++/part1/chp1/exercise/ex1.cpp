#include <iostream>

int main(void)
{
    int result = 0;
    int temp;
    for(int i = 0; i < 5; i++)
    {
        std::cout << i+1 << "번째 정수 입력: ";
        std::cin >> temp;
        result += temp;
    }

    std::cout << "합계: " << result << std::endl;
}