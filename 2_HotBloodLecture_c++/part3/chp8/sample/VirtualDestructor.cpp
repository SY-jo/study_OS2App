#include <iostream>

using namespace std;

class First
{
private:
    int* one;
public:
    First(void)
    {
        one = new int;
    }
    ~First(void)
    {
        delete one;
        cout << "Destructor from First" << endl;
    }
};

class Second : public First
{
private:
    int* two;
public:
    Second(void)
    {
        two = new int;
    }
    ~Second(void)
    {
        delete two;
        cout << "Destructor from Second" << endl;
    }
};

int main(void)
{
    First* test = new Second;

    delete test;

    return 0;
}