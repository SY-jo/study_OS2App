#include <iostream>
#include <string.h>
#include <stdlib.h>

char* Dynamic_str(int len)
{
    // char* pstr = (char*) malloc(sizeof(char) * len);
    char *pstr = new char[len];

    return pstr;
}

int main(void)
{
    char* str = Dynamic_str(20);
    
    strcpy(str, "Hello2");

    std::cout << str << std::endl;
    
    // free(str);
    delete(str);

    return 0;
}