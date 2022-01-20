#include <iostream>

using namespace std;

void Increase_Variable(int &val);
void Reverse_Variable(int &val);

int main(void)
{
    int num = 4;
    cout << num << endl;

    Increase_Variable(num);
    cout << num << endl;

    Reverse_Variable(num);
    cout << num << endl;
}

void Increase_Variable(int &val)
{
    val++;
}

void Reverse_Variable(int &val)
{
    val *= (-1);
}