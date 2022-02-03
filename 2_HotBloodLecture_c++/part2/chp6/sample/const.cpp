#include <iostream>

class myClass
{
private:
    int num;
    const int num2 = 9;
public:
    myClass(int n) : num(n) {}
    myClass& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowNum(void) const
    {
        std::cout << "const " << num << std::endl;
    }
    void ShowNum(void)
    {
        std::cout << num << std::endl;
    }
    void ShowNum2(void)
    {
        std::cout << num2 << std::endl;
    }
};

int main(void)
{
    int num3 = 11;
    int& ref = num3;
    ref++;

    myClass test(3);
    test.ShowNum();
    test.ShowNum2();
    std::cout << num3 << std::endl;
    
    //test.AddNum(1).AddNum(2);
    //test.ShowNum();

    return 0;
}