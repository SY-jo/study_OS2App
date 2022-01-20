#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;

int main(void)
{
    int radm;

    for(int i = 0; i < 5; i++)
    {
        srand((unsigned int)time(NULL));
        radm = rand();
        radm %= 100;

        cout << radm << endl;
    }

    return 0;
}