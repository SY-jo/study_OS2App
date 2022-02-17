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

Account& Account::operator=(const Account &ref)
{
    ID = ref.ID;
    balance = ref.balance;

    delete[] name;
    name = new char[strlen(ref.name)+1];
    strcpy(name, ref.name);
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

NormalAccount::NormalAccount(int _ID, char* _name, int _balance, float _interestRate)
    : Account(_ID, _name, _balance), interestRate(_interestRate)
{ 

}

void NormalAccount::Change_interest(void)
{
    int interest = (int) (0.01 * interestRate * Show_Balance());
    Change_balance(interest);
}

float NormalAccount::Show_InterestRate(void) const
{
    return interestRate;
}

HighCreditAccount::HighCreditAccount(int _ID, char* _name, int _balance, float _interestRate, CreditRank _rank)
    : NormalAccount(_ID, _name, _balance, _interestRate), rank(_rank)
{

}


void HighCreditAccount::Change_interest(void)
{
    int interest = (int)(0.01 * (Show_InterestRate() + rank) * Show_Balance());
    Change_balance(interest);
}
