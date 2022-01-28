#include <iostream>

class myClass
{
private:
    int num;
public:
    myClass(int _num) : num(_num) { }
    void ShowNum(void)
    {
        std::cout << num << std::endl;
    }
};

int main(void)
{
    myClass sample(3);
    sample.ShowNum();

    myClass sample2 = 7;
    sample2.ShowNum();

    return 0;
}