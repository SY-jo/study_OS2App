#include <iostream>

using namespace std;

void PositiveNumChecker(int num) //throw(int)
{
    if(num < 0)
        throw -1;
    
    cout << "No Exception Detected!" << endl;
}

int main(void)
{
    int num;
    cout << "Insert Positive Number : "; cin >> num;

    while(1)
    {
        try
        {
            PositiveNumChecker(num);
            break;
        }
        catch(int err)
        {
            cout << "Wrong!" << endl;
        cout << "Re-Insert Positive Number : "; cin >> num;
        }
    }
}