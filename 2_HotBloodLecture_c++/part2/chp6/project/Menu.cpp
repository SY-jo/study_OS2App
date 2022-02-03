#include "Menu.h"

void Menu::Show_Menu(void)
{
    cout << endl;
    cout << "|----Menu---- \t|" << endl;    
    cout << "|1. ���°��� \t|" << endl;
    cout << "|2. �Ա� \t|" << endl;
    cout << "|3. ��� \t|" << endl;
    cout << "|4. �������� ��ü ��� \t|" << endl;
    cout << "|5. ���� \t|" << endl;
    cout << "|------------ \t|" << endl;
}

void Menu::Input_Select(void)
{
    int temp; 
    cin >> temp; //���⼭ stdin �� �������ڰ� �ƴ� �ٸ��� ���������, �������� Input_Select�� call���� �� ���õ�. ���۸� ����ִ� �Լ� �ʿ�
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

    cout << "[���°���]\n";
    cout << "����ID : "; cin >> ID;
    cout << "�̸� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> balance;

    Account *NewAccount = new Account(ID, name, balance);
    
    sClients[idx_client++] = NewAccount;
}


void Menu::Command_Deposit(void)
{
    int ID;
    int money;
    
    cout << "[�Ա�]";
    cout << "����ID : "; cin >> ID;
    cout << "�Աݾ� : "; cin >> money;
    
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
    
    cout << "[���]";
    cout << "����ID : "; cin >> ID;
    cout << "��ݾ� : "; cin >> money;
    
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
        cout << "����ID : " << sClients[i]->Show_ID() << endl;
        cout << "�̸� : " << sClients[i]->Show_Name() << endl;
        cout << "�Աݾ� : " << sClients[i]->Show_Balance() << endl;
    }
}


