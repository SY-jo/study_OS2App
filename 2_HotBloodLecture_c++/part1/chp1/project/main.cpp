#include <iostream>

using::std::cout;
using::std::cin;
using::std::endl;

typedef struct account
{
    int ID;
    char name[10];
    uint balance; 
} account_t;

typedef enum select
{
    OpenAccount = 1,
    Deposit,
    Withdraw,
    InfoAccountAll,
    Exit
} select_t;


void Menu_display(void);
void Menu_select(select_t* select);
void Menu_error_input(void);
void Menu_exit(void);
account_t Menu_input_NewAccount(void);
account_t Menu_input_deposit(void);
account_t Menu_input_withdraw(void);

void Account_display_all(void);
void Account_new(void);
void Account_deposit(void);
void Account_withdraw(void);
void Account_change_balance(account_t data);

static account sClients[100];
static uint idx_client = 0;

int main(void)
{
    select_t select;

    while(1)
    {
        Menu_display();
        Menu_select(&select);

        switch(select)
        {
            case OpenAccount:
                Account_new();
                break;
            case Deposit:
                Account_deposit();
                break;
            case Withdraw:
                Account_withdraw();
                break;
            case InfoAccountAll:
                Account_display_all();
                break;
            case Exit:
                Menu_exit();
                return 0;
                break;
            default:
                Menu_error_input();
                break;
        }
    }
}

void Menu_display(void)
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

void Menu_select(select_t* select)
{

    int temp;
    cin >> temp;
    *select = (select_t)temp;
}

void Menu_error_input(void)
{

    cout << "Wrong input! \n" << endl;
    cout << "Try again \n\n" << endl;
}


void Menu_exit(void)
{

    cout << "Exit.." << endl;
}

account_t Menu_input_NewAccount(void)
{
    account_t data;

    cout << "[계좌개설]\n";
    cout << "계좌ID : ";
    cin >> data.ID;
    cout << "이름 : ";
    cin >> data.name;
    cout << "입금액 : ";
    cin >> data.balance;

    return data;
}

account_t Menu_input_deposit(void)
{
    account_t data;
    
    cout << "[입금]";
    cout << "계좌ID : ";
    cin >> data.ID;
    // cout << "이름 : " << endl;
    // cin >> data.name;
    cout << "입금액 : ";
    cin >> data.balance;

    return data;
}

account_t Menu_input_withdraw(void)
{
    account_t data;
    
    cout << "[출금]";
    cout << "계좌ID : ";
    cin >> data.ID;
    // cout << "이름 : " << endl;
    // cin >> data.name;
    cout << "출금액 : ";
    cin >> data.balance;

    return data;
}

void Account_display_all(void)
{
    for(int i = 0; i < idx_client; i++)
    {
        account_t client = sClients[i];

        cout << "계좌ID : " << client.ID << endl;
        cout << "이름 : " << client.name << endl;
        cout << "입금액 : " << client.balance << endl;
    }
    
}

void Account_new(void)
{
    account_t data;
    data = Menu_input_NewAccount();

    sClients[idx_client++] = data;
}

void Account_deposit(void)
{
    account_t data;
    data = Menu_input_deposit();
    
    Account_change_balance(data);
}

void Account_withdraw(void)
{
    account_t data;
    data = Menu_input_withdraw();
    data.balance *= (-1);   //출금으로 동작하도록
    
    Account_change_balance(data);
}

void Account_change_balance(account_t data)
{
    for(int i = 0; i < idx_client; i++)
    {
        if(sClients[i].ID == data.ID)
        {
            sClients[i].balance += data.balance;
            break;
        }
    }
}