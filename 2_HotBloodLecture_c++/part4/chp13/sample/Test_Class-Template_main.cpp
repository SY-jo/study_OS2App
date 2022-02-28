// class template 를 이용해 정의한 class를 hearder 와 source 분리해서 main code 와 별도로 컴파일할 때,
// main file에서 header 와 source 를 모두 #include 해야된다캄.
// 근데 그 논리되로라면 template이 사용안 된 경우에도 에러났어야 하는거 아닌가?
// 테스트

#include "Test_Class-Template.h"
#include <iostream>

using std::cout;
using std::endl;


int main(void)
{
    myClass1 test(1);
    cout << test.GetMem() << endl;

    myClass2<char> test2('A');
    cout << test2.GetMem() << endl;

    return 0;
}