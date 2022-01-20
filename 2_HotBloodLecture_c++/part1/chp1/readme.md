# Part1
## Chp 01

### chp 1-1 : iostream의 std::cout, std::cin 을 이용한 기본적인 입출력
<br/>

### chp 1-2 : function overloading 소개
- 동일한 함수명 + 동일한 출력타입 + 다른 입력변수 개수 및 타입
- ex)
  ``` c 
  void myFunc(char ch);
  void myFunc(int a);
  int myFunc(int a, int b); <---- (x)
<br/>

### chp 1-3 : function argument 의 default 값 지정
- function prototype 선언시에 초기값을 같이 적어주면됨
  - ex) `void myFunc(int a = 3)` 로 선언. main()에서 myFunc()으로 인자 없이 호출하면, 기본적으로 a = 7 이 대입된 상태가 됨
* 이 때, 함수 오버로딩과 함께 쓸 경우에는 어떤 함수를 사용하는 건지 모호하면 빌드 에러 발생

    ``` c
    void MyFunc(void)
    {
        std::cout << "MyFunc(void)" << std::endl;
    }

    void MyFunc(int a = 3)
    {
        std::cout << "MyFunc(int a)" << std::endl;
    }

    int main(void)
    {
        MyFunc(); // MyFunc(void)을 호출하는 것인지, MyFunc(int)를 호출하면서 a = 3 default value를 사용하는 것인지 분명하지 않음
    }
    ```
* 일부 argument 에 대해서만 default 값 지정 가능. 단, 모호함을 없애기 위해 default가 지정되지 않은 argument들은 왼쪽에 몰려 있어야됨
    ``` c 
    void myFunc(int a, int b = 2, int c = 3);

    myFunc(4, 5, 6); // a = 4, b = 5, c = 6
    myFunc(4, 5);    // a = 4, b = 5, c = 3
    myFunc(4);       // a = 4, b = 2, c = 3


    void myFunc(int a = 1, int b, int c); <--- (x)
    ```
    
<br/>

## chp 1-4 : in-line function
- c언어에서의 매크로함수를 확장한 것
    ``` c
    // c
    #define SQUARE(x)   ((x) * (x))
    ```
    ``` c++
    // c++
    inline int SQUARE(int x)
    {
        return x*x;
    }
    ```
- 매크로함수와 동일하게 별도의 코드 영역을 가지지 않게 된다?(추측)
- 매크로 함수는 전처리기에 의해 기계적으로 처리되지만,   
인라인 함수는 컴파일러에 의해 최적화 됨.    
컴파일러가 판단하기에 그냥 함수로 사용하는게 효율적이다하면 inline keyword를 무시하고, 반대로 일반적인 함수에 inline 을 붙이기도 함.
- 다만 매크로함수와 다르게 입출력 데이터타입에 의존성을 가지게 되는데,   
이 점은 'template'이란걸 사용하면 해결할 수 있다캄. 나중에 나올 예정

<br/>

## chp 1-5 : namespace 소개
- Scope resolution operator(범위지정연산자) ::
- variable 과 function 의 이름이 곂치는 문제를 방지하기 위해 도입
- namespace 안에 namespace를 중첩시켜 정의하는 것도 가능
- 예시
    ``` c++
    namespace A
    {
        void Test(void);
        void Hi(void);

        namespace AA
        {
            static int sVal = 7;
        }

        namespace BB
        {
            static int sVal = 11;
        }
    }

    ...

    void A::Test(void)
    {
        std::cout << "Test from namespace A" << std::endl;
        Hi(); // A::Test() 와 동일한 namespace 안에 있는 놈인 경우, A::Hi()로 할 필요x
    }

    void A::Hi(void)
    {
        std::cout << "Hi" << std::endl;
    }
    ```
- using 키워드
    - `using A::myFunc` : {} 안에서 myFunc을 호출할 때 myFunc()으로 사용 가능
    - 전역 영역에서 선언하면 해당 소스코드 전체에 적용
    - `using namespace std` : std namespace 안에 있는 모든 name들을 'std::' 없이 사용 가능. 일일히 지정하는 것 보다 편하지만, 이름충돌의 위험성이 높아지는 안 좋은 습관
- namespace Alias 별칭 지정
    ``` c++
        namespace AA
        {
            namespace BB
            {
                namespace CC
                {
                    int val;
                }
            }
        }

        ...

        AA::BB::CC::val;
        
        namespace ABC = AA::BB::CC;
        ABC::val;
        ```
