#ifndef MENU_H_
#define MENU_H_


#include <iostream>
#include "Account.h"

extern Account* sClients[100];
extern int idx_client;

using::std::cout;
using::std::cin;
using::std::endl;

class Menu
{
public:
    int select;
    enum SELECT
    {
        OpenAccount = 1,
        Deposit,
        Withdraw,
        InfoAccountAll,
        EXIT
    };

    void Show_Menu(void);
    void Input_Select(void);
    void Error_WrongCommand(void);
    void Error_WrongID(void);
    void Exit(void);
    int IDtoIndex(int ID);


    Account* Command_OpenAccount(void);
    void Command_Deposit(void);
    void Command_Withdraw(void);
    void Command_ShowAccountAll(void);

};




#endif
