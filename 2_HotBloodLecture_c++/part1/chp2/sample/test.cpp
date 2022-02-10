#include <iostream>

using namespace std;

int& RefRetFunc(int ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 7;

    int &num2 = RefRetFunc(num1);

    cout << num2 << endl;
    cout << &num2 << endl;
    cout << &num1 << endl;


    return 0;
}