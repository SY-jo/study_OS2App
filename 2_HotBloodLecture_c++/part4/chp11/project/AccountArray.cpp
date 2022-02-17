#include "AccountArray.h"

AccountArray::AccountArray(int len) : arrlen(len)
{
    arr = new Account_PTR[len];
}

AccountArray::~AccountArray()
{
    delete[] arr;
}

Account_PTR& AccountArray::operator[](const int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

Account_PTR AccountArray::operator[](const int idx) const
{
    cout << "const" << endl;
    if(idx < 0 || idx>=arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

int AccountArray::GetArrlen() const
{
    return arrlen;
}