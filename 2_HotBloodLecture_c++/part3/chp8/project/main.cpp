#include "Account.h"
#include "Menu.h"


int main(void)
{
    Menu menu;
    
    // freopen("TestInput.txt", "r", stdin); // 테스트입력 자동으로

    while(1)
    {
        menu.Show_Menu();
        menu.Input_Select();

        switch(menu.select)
        {
            case Menu::SELECT::OpenAccount:
                menu.Command_OpenAccount();
                break;
            case Menu::SELECT::Deposit:
                menu.Command_Deposit();
                break;
            case Menu::SELECT::Withdraw:
                menu.Command_Withdraw();
                break;
            case Menu::SELECT::InfoAccountAll:
                menu.Command_ShowAccountAll();
                break;
            case Menu::SELECT::EXIT:
                menu.Exit();
                return 0;
                break;
            default:
                menu.Error_WrongCommand();
                break;
        }
    }
}
