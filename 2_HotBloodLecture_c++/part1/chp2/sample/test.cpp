#include <iostream>

using namespace std;

int& RefRetFunc(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 7;

    int &num2 = RefRetFunc(num1);

    cout << num1 << endl;
    cout << num2 << endl;

    num1++;
    cout << num1 << endl;
    cout << num2 << endl;

    num2++;
    cout << num1 << endl;
    cout << num2 << endl;


    return 0;
}