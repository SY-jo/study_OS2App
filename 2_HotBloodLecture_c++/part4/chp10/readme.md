# Chp 10 

## Operation Overloading 소개
* 이미 존재하는 연산자에 대해서 새로운 기능을 정의하는것
  * Object에도 연산자를 사용할 수 있게 하기 위한 기능
  * 존재하지 않는 연산자(ex:$)는 overloading 할 수 없음
* 크게 2가지 방식 존재 : 1. method에 의한 overloading 2. global function에 의한 overloading (1.을 주로 사용)
* 치환관계
  * ``` c++
    class myClass
    {
        ...
        myClass operator+(const myClass& ref) const
        {
            myClass result(mNum + ref.mNum);
            return result;
        }
        ...
    }

    ...

    myClass obj3 = obj1 + obj2 // <==> obj1.operator+(obj2);
    ```
* Overloading이 불가능한 operator
  * .
  * .*
  * ::
  * ?:
  * sizeof
  * typeid
  * static_cast
  * dynamic_cast
  * const_cast
  * reinterpret_cast
* Member function 으로만 Overloading 가능한 operator
  * =
  * ()
  * []
  * ->
  