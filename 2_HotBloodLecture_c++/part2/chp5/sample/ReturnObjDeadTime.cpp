#include <iostream>

using std::cout;
using std::endl;

static int sNumOfNewObj = 0; 

class myClass
{
private:
    int num;
public:
    myClass(int _num) : num(_num)
    {
        cout << "New Object : " << this << endl;
        sNumOfNewObj++;
    }
    myClass(const myClass &copy) : num(copy.num)
    {
        cout << "New Copy obj : " << this << endl;
        sNumOfNewObj++;
    }
    ~myClass(void)
    {
        cout << "Del obj : " << this << endl;
    }
};

const myClass& myfunc(const myClass& ob) // 여기서 input을 value로 하냐 reference로 하냐 차이
{
    cout << "Parm address : " << &ob << endl;
    return ob;
}

int main(void)
{
    myClass obj(3);
    myfunc(obj);

    cout << endl;

    myClass temp = myfunc(obj); 
    // myfunc의 return type이 myClass 인 경우 :  temp object가 새롭게 생성되지는 않고, return되는 object의 이름이 temp가 됨
    // myfunc의 return type이 myClass& 인 경우 : temp object의 copy constructor가 실행됨

    cout << endl ;

    cout << "The number of total Object Construction : " << sNumOfNewObj << endl << endl;

    return 0;
}

