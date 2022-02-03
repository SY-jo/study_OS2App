#include "Account.h"

Account::Account(int _ID, char* _name, int _balance) 
    : ID(_ID), balance(_balance) 
{
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
}

Account::Account(const Account &ref)
    : ID(ref.ID), balance(ref.balance)
{
    name = new char[strlen(ref.name) + 1];
    strcpy(name, ref.name);
}


Account::~Account(void)
{
    delete []name;
}

void Account::Change_balance(int money)
{
    balance += money;
}

int Account::Show_ID(void) const
{
    return ID;
}
char* Account::Show_Name(void) const
{
    return name;
}

int Account::Show_Balance(void) const
{
    return balance;
}