#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class myClass
{
private:
    static T mem;
public:
    void AddMem(const T _num)
    {
        mem += _num;
    }
    void ShowMem(void)
    {
        cout << mem << endl;
    }
};

template <typename T>
T myClass<T>::mem = 0;

int main(void)
{
    myClass<int> j;
    j.AddMem(3);
    j.ShowMem();

    myClass<int> jj;
    j.ShowMem();

    myClass<float> i;
    myClass<float> ii;
    ii.AddMem(7.0);
    i.ShowMem();

    return 0;
}