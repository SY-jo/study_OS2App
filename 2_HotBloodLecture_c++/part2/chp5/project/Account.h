#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <cstring>

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

    void Change_balance(int money);
    int Show_ID(void);
    char* Show_Name(void);
    int Show_Balance(void);
};


#endif