#include <iostream>
#include "Namecard.h"

int main(void)
{
    NameCard manClerk("LEE", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    manClerk.ShowNameCardInfo();
    return 0;
}