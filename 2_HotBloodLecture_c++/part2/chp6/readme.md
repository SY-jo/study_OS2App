
# Chp 6 : keyword const, friend, static, mutable

## Chp 6-1 : const
- case : variable
  - `const int lucky = 7`
  - 선언만 하고 초기화를 안 하면 -> 컴파일 에러
  - 초기화된 lucky 변수를 변화시키는 명령어 -> 컴파일 에러
- case : member variable
  - const variable과 동일
- case : pointer
  - 2가지 용법
  - `const int* ptr`
    - `(const int)` 에 대한 포인터라고 이해
    - *ptr을 이용한 변수값 변경 -> 컴파일 에러
  - `int* const ptr`
    - ptr 이 가르키는 주소 변경 -> 컴파일 에러
- case : object
  - `const myClass example(3)`
  - 초기화된 example 오브젝트의 member variable을 변화시키는 메소드 -> 컴파일 에러
  - const method 만 사용 가능해짐 (ex : `void ShowMenber(void) const { cout << member << endl }`
- case : function
  - const method : `void Method(void) const { some actions }`
    - member variable 의 값을 바꾸지 않는 method 에 사용하는 키워드. 
    - 해당 method가 member variable을 변화시키면 컴파일 에러를 내줘서 버그 예방
    - const 키워드 사용유무에 따라 function overriding 또한 가능.
    - const object 는 const method를 선택함. method가 일반버전 밖에 없으면 상관 없이 동작
  -  const argument : `void Method(const int& arg) { some actions }`
     -  call-by-reference 로 들어오는 매개변수 arg 의 value를 변화시키지 않겠다는 의미
  -  const return : `const myClass& Method(void) { some actions }`
     -  method의 출력결과로 나오는 class를 변형시키지 못 하도록 하겠다는 의미

## Chp 6-2 : friend
- 클래스의 정의에서 friend 키워드를 사용하면, 다른 class 혹은 method 가 아닌 일반적인 전역함수가 private: 에 접근할 수 있도록 허용한다.
- ex
  ``` c++
    class myClass
    {
    friend class myAnotherClass;  // 다른 클래스
    friend void myOtherClass::method(myClass& ref); // 다른 클래스 안의 특정 메소드
    friend void myFunc(myClass& ref); // 전역함수
    private:
        int num;
    public:
        ...
    }
  ```
- 논란이 많은 문법이라캄. 알아두기만하고 사용자제

## Chp 6-3 : static
- C 에서의 static
  - ex
    ``` c
        void myFunc(void)
        {
            static int num;
            num++
        }
    ```
  - static variable 은 memory 에서 data 영역에 할당됨 (<-> const variable은 stack. 따라서 scope을 벗어나면 memory에서 지워짐)
  - static variable 은 해당 scope 안에서만 사용 가능
    - 따라서 전역변수에 static keyword를 사용한 static global variable은 해당 source file 안에서만 접근가능
  - 별도로 초기화를 하지 않으면, 0 으로 초기화됨
- C++ 에서의 static (\w Class)
  - ex
    ``` c++
        class myClass
        {
        private:
            int num;
            static int sNum;
        public:
            ...
        }
        int myClass::sNum = 7; //초기화를 이런식으로 해줘야 되도록 문법을 정함
    ```
  - static member varaible 은 object의 일부로써 stack에 올라가지 않고, data에 저장되어 있음.
  - 해당 클래스의 오브젝트끼리만 공유하는 global varaible 처럼 사용가능

## Chp 6-4 : mutable
- `mutable int num`
- member variable 이 const method 안에서도 값이 변할 수 있도록 예외를 줌
- const keyword 의 효력을 약화시킴. 알아두기만 하고 사용자제