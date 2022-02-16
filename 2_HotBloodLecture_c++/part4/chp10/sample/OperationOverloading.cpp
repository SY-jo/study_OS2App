#include <iostream>

class myClass
{
private:
    int mNum;
public:
    myClass(int _mNum = 0)
        : mNum(_mNum) {
    }
    ~myClass(void)
    {
        std::cout << "Destructor called" << std::endl;
    }
    
    myClass operator+(const myClass& ref) const
    {
        myClass result(mNum + ref.mNum);
        return result;
    }

    int operator$(const myClass& ref)
    {
        return mNum + ref.mNum;
    }

    void Get_mNum(void)
    {
        std::cout << mNum << std::endl;
    }
};

int main(void)
{
    myClass tem1(1);
    myClass tem2(2);
    myClass tem3 = tem1 + tem2;
    tem3.Get_mNum();

    int result = tem1.operator$(tem2);
    // myClass tem4(tem1 $ tem2);
    // tem4.Get_mNum();
}
