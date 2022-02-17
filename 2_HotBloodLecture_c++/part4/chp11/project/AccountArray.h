#ifndef ACCOUNTARRAY_H_
#define ACCOUNTARRAY_H_

#include "Account.h"
#include <iostream>

using std::cout;
using std::endl;

typedef Account* Account_PTR;

class AccountArray
{
private:
    Account_PTR* arr;
    int arrlen;

    AccountArray(const AccountArray&) {}
    AccountArray& operator=(const AccountArray&) {}
public:
    AccountArray(int len);
    ~AccountArray(void);

    Account_PTR& operator[](const int idx);
    Account_PTR operator[](const int idx) const;

    int GetArrlen() const;
};

#endif