#include <iostream>

using namespace std;

class First
{
public:
    void print(void)
    {
        cout << "First" << endl;
    }
};

class Second : public First
{
public:
    void print(void)
    {
        cout << "Second" << endl;
    }
};

int main(void)
{
    First one;
    Second two;

    one.print();
    two.print();

    First* first = new First;
    First* second = new Second;

    first->print();
    second->print();

    delete first;
    delete second;

    return 0;
}