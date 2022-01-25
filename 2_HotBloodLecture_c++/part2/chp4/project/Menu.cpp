#include "Menu.h"

void Menu::Show_Menu(void)
{
    cout << endl;
    cout << "----Menu----" << endl;    
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 종료" << endl;
    cout << "------------" << endl;
}

void Menu::Input_Select(void)
{
    cin >> select;
}

void Menu::Error_WrongCommand(void)
{
    cout << "Wrong Command" << endl;
}

void Menu::Error_WrongID(void)
{
    cout << "Wrong ID" << endl;
}

void Menu::Exit(void)
{
    cout << "Exit.." << endl;
    
    for(int i=0; i < idx_client; i++)
        delete sClients[i];
}

int Menu::IDtoIndex(int ID)
{
    for(int i = 0; i < idx_client; i++)
    {
        if(sClients[i]->Show_ID() == ID)
        {
            return i;
        }
    }

    return -1;
}


Account* Menu::Command_OpenAccount(void)
{
    int ID;
    char name[10];
    int balance; 

    cout << "[계좌개설]\n";
    cout << "계좌ID : "; cin >> ID;
    cout << "이름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;

    Account *NewAccount = new Account(ID, name, balance);
    
    sClients[idx_client++] = NewAccount;
}


void Menu::Command_Deposit(void)
{
    int ID;
    int money;
    
    cout << "[입금]";
    cout << "계좌ID : "; cin >> ID;
    cout << "입금액 : "; cin >> money;
    
    int idx = IDtoIndex(ID);
    if(idx == -1)
        Error_WrongID();
    else
        sClients[idx]->Change_balance(money);
}


void Menu::Command_Withdraw(void)
{
    int ID;
    int money;
    
    cout << "[출금]";
    cout << "계좌ID : "; cin >> ID;
    cout << "출금액 : "; cin >> money;
    
    int idx = IDtoIndex(ID);
    if(idx == -1)
        Error_WrongID();
    else
        sClients[idx]->Change_balance(money * (-1));
}

void Menu::Command_ShowAccountAll(void)
{
    for(int i = 0; i < idx_client; i++)
    {
        cout << "계좌ID : " << sClients[i]->Show_ID() << endl;
        cout << "이름 : " << sClients[i]->Show_Name() << endl;
        cout << "입금액 : " << sClients[i]->Show_Balance() << endl;
    }
}


