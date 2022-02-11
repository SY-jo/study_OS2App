#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(char* _name, int _age)
        : age(_age)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    ~MyFriendInfo(void)
    {
        delete[] name;
    }
    void ShowMyFriendInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(char* _name, int _age, char* _addr, char* _phone)
        : MyFriendInfo(_name, _age)
    {
        addr = new char[strlen(_addr) + 1];
        strcpy(addr, _addr);
        phone = new char[strlen(_phone) + 1];
        strcpy(phone, _phone);
    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
    void ShowMyFriendDetailInfo(void)
    {
        ShowMyFriendInfo();
        cout << "Address : " << addr << endl;
        cout << "Phone : " << phone << endl << endl;
    }
};

int main(void)
{
    MyFriendDetailInfo Me("jo", 27, "Ilsan", "010-1234-5678");

    Me.ShowMyFriendDetailInfo();

    return 0;
}