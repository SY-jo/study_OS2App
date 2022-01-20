#include <iostream>

int main(void)
{
    int val = 0;
    while(1)
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin >> val;

        if(val == -1)
        {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }
        
        int wage = 50;
        wage += val * 0.12;
        std::cout << "이번 달 급여: " << wage << "만원" << std::endl;
        
    }
    
}