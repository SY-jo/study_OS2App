#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <cstring>

enum CreditRank
{
    A = 7,
    B = 4,
    C = 2,
};

class Account
{
private:
    int ID;
    char* name;
    int balance;
public:
    Account(int _ID, char* _name, int _balance);
    Account(const Account &ref);
    ~Account(void);

    virtual void Change_interest(void) = 0;
    void Change_balance(int money);
    int Show_ID(void) const;
    char* Show_Name(void) const;
    int Show_Balance(void) const;
};

class NormalAccount : public Account
{
private:
    const float interestRate;
public:
    NormalAccount(int _ID, char* _name, int _balance, float _interestRate);
    float Show_InterestRate(void) const;
    virtual void Change_interest(void);
};

class HighCreditAccount : public NormalAccount
{
private:
    CreditRank rank;
public:
    HighCreditAccount(int _ID, char* _name, int _balance, float _interestRate, CreditRank _rank);
    virtual void Change_interest(void);
};


#endif