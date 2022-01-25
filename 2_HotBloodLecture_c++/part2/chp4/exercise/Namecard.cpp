#include "Namecard.h"

void COMP_POS::ShowPositionInfo(int _rank)
{
    switch(_rank)
    {
    case Rank_e::CLERK:
        std::cout << "CLERK";
        break;
    
    case Rank_e::SENIOR:
        std::cout << "SENIOR";
        break;
    
    case Rank_e::ASSIST:
        std::cout << "ASSIST";
        break;
    
    case Rank_e::MANAGER:
        std::cout << "MANAGER";
        break;
    
    }

}


NameCard::NameCard(char* Name, char* Company, char* Phone, COMP_POS::Rank_e Rank)
{
    using std::strlen;
    using std::strcpy;

    name = new char[strlen(Name)]; strcpy(name, Name);
    company = new char[strlen(Company)]; strcpy(company, Company);
    phone = new char[strlen(Phone)]; strcpy(phone, Phone);
    rank = Rank;
}

NameCard::~NameCard(void)
{
    delete []name;
    delete []company;
    delete []phone;
}

void NameCard::ShowNameCardInfo()
{
    using std::cout;
    using std::endl;
    cout << "Name : " << name << endl;
    cout << "Company : " << company << endl;
    cout << "Phone : " << phone << endl;
    cout << "Rank : "; COMP_POS::ShowPositionInfo(rank); cout << endl;
    cout << endl;
}