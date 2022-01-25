#ifndef NAMECARD_H_
#define NAMECARD_H_

#include <iostream>
// #include <string.h>
#include <cstring>

namespace COMP_POS
{
    enum Rank_e {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int _rank);
};

class NameCard
{
private:
    char* name;
    char* company;
    char* phone;
    int rank;  

public:
    NameCard(char* Name, char* Company, char* Phone, COMP_POS::Rank_e Rank);
    ~NameCard();
    void ShowNameCardInfo();
};
#endif