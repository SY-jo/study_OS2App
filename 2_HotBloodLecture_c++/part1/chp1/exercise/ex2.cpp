#include <iostream>

int main(void)
{
    char name[20];
    char phone[20];

    std::cout << "Name : ";
    std::cin.getline(name, 20); // 이렇게 사용해야 띄어쓰기도 입력됨
    // std::cin >> name;

    std::cout << "Phone : ";
    std::cin >> phone;

    std::cout << "------Input Data------" << std::endl;
    std::cout << "Name : " << name << std::endl;
    std::cout << "Phone : " << phone << std::endl;
    

}