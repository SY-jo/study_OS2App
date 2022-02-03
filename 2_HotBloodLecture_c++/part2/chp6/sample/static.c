#include <stdio.h>

void myFunc(void)
{
    static int num;
    static char ch = 'a';
    num++;
    ch++;
    printf("%d \n", num);
    printf("%c \n", ch);
}

int main(void)
{
    myFunc();
    myFunc();
    myFunc();

    return 0;
}