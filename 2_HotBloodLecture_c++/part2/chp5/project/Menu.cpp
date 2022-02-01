#include "Menu.h"

void Menu::Show_Menu(void)
{
    cout << endl;
    cout << "|----Menu---- \t|" << endl;    
    cout << "|1. 계좌개설 \t|" << endl;
    cout << "|2. 입금 \t|" << endl;
    cout << "|3. 출금 \t|" << endl;
    cout << "|4. 계좌정보 전체 출력 \t|" << endl;
    cout << "|5. 종료 \t|" << endl;
    cout << "|------------ \t|" << endl;
}

void Menu::Input_Select(void)
{
    int temp; 
    cin >> temp; //여기서 stdin 에 정수숫자가 아닌 다른게 들어있으면, 다음번에 Input_Select가 call됐을 때 무시됨. 버퍼를 비워주는 함수 필요
    if(SELECT::OpenAccount <= temp && temp <= SELECT::EXIT)
        select = temp;
    else
        select = -1;
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


