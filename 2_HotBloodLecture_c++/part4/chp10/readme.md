# Chp 10 

## Operation Overloading 소개
* 이미 존재하는 연산자에 대해서 새로운 기능을 정의하는것
  * Object에도 연산자를 사용할 수 있게 하기 위한 기능
  * 존재하지 않는 연산자(ex:$)는 overloading 할 수 없음
* 크게 2가지 방식 존재 : 1. method에 의한 overloading 2. global function에 의한 overloading (1.을 주로 사용)
* 이항연산자, 전위/후위 단항연산자 가능, operand의 type이 서로 다르더라도 동작가능하게 짜는 것 가능
* Syntax
  * 이항연산자
    ``` c++
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
  * 단항연산자 
    ``` c++
    class myClass
    {
      ...
      myClass operator++(void) // 전위. ++obj <==> obj.operator++()
      {
        myClass result(m_Num + 1);
        return result;
      }
      ...
      myClass operator++(int) // 후위. obj++ <==> obj.operator++(int). int는 전위/후위를 구분하기 위해 C++에서 정한 약속. 따로 의미가 있는 것은 아님
      {
        myClass retobj(*this);
        m_Num += 1;
        return retobj; // 원래의 값을 가지고 있는 임시객체를 반환
      }
    }
    ```
  * 전역함수를 이용한 선언
    ``` c++
    class myClass
    {
      ...
      friend myClass operator+(const myClass&, const myClass&); // 전역함수에서 object의 private scope에 접근할 수 있도록 하기 위한 선언
      ...
    }

    myClass operator+(const myClass& ref1, const myClass& ref2)
    {
      myClass result(ref1.m_Num1 + ref2.m_Num2);
      return result;  
    }
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
* 교환법칙
  * operator overloading은 기본적으로 `obj<연산자>` 의 형태로만 적용가능.
  * 하지만 직관적으로 +, * 과 같은 연산은 교환법칙이 성립할 수 있도록 `<연산자> obj` 의 꼴로도 사용할 수 있게 하는 게 좋음
  * 전역함수를 이용하여 구현
   ``` c++
   // int값과의 +연산에 대해 overloading 해둔 myClass 를 가정
   myClass operator+(int num, myClass ref)
   {
     return ref+num;
   }
   
   ```
* cout, endl 의 정체
  * 위 function overloading 을 이용해서 std::cout, std::endl 이 구현됨
  * cout 은 iostream 이라는 이름의 class 이고, `<<` 연산자를 다양한 자료형에 대해 overloading 해두었음
  * endl 은 `"\n"` 을 출력하고, stdout 버퍼를 비우는 메소드임 