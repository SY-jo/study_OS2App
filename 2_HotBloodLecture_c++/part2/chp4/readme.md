# Chp 4 : Class 완성?

## 4-1 : Infomation Hiding // 프로그래머의 실수를 방지하기 위한 문법
1. 정보은닉 Information Hiding
    - private: 을 사용하여 주요 member variable 을 자유롭게 초기화나 조작하는 걸 방지
    - 대신에 public: 에서 member variable 을 초기화, 접근, 조작 하는 member function 을 정의해서 사용
    - ex : 냉장고에 있는 물건들을 class 로 만들어서 관리하는 프로그램
      - 각 음식들의 개수가 member variable 가 될 것인데, 이건 음수가 되서는 안 됨
      - 근데 실수로 음식의 개수를 나타내는 mem. variable 이 음수가 되는 코드가 짜여지더라도, 컴파일러는 에러를 내지 않음
      - 때문에 음식의 개수에 접근하는 member function을 만들고, 안에 예외처리를 위한 if문을 준비해두어 실수를 방지
    - member variable의 값을 읽어서 반환해주는 access function 또한 클래스에 기본적으로 포함시켜주는게 좋음
2. Const function
     - member variable을 값을 변경시키지 않는 member function에 const 키워드를 달아준 것
         ``` c++
         class myClass
         {
         private
             char name[10];
             ...
         public:
             char* GetName(void) const;
             ...
         }
         ```
     - const function 안에서 다른 member function을 호출하는 경우, 해당 member function도 const가 아니면 컴파일러 에러가 남
     - const referenced 를 인풋으로 받는 함수를 const function으로 안 하면 컴파일러 에러

## 4-2 : Encapsulation
   - 객체를 묘사하는데 필요한 요소들 또한 객체화하여 구조를 짜는 것
   - ex : class 롱티
     - 롱티는 보드카, 데낄라, 진, 럼, 콜라 객체를 member variable로 가짐
     - 롱티의 성분을 출력해주는 member function을 짤 때,
       - 재료들이 되는 객체의 class를 정의할 때, 양을 의미하는 variable을 public으로 해두면, 직접 멤버들의 값을 읽어와서 출력하면 되지만
       - 위같이 하기 보다, 재료들의 member variable은 private으로 유지하고, 재료들의 양을 출력해주는 member function을 정의해놓고, 이걸로부터 양을 받아서 조합하는게 좋다캄
       - 왜? 계층화된 구조를 유지하는게 유지보수에 좋으니까?
     
## 4-3 : Constructor & Destructor
   - Constructor

        ``` c++
            class subClass
            {
            private:
                int num;
            public:
                subClass(void)
                {
                    num = 0;
                }
                
                subClass(int n)
                {
                    num = 1;
                }
                ...
            };

            class myClass
            {
            private:
                subClass sub1;
                subClass sub2;
            ...
            public:
                myClass(int n1, int n2)
                    :subClass(n1), subClass(n2)
                {
                    //empty
                }
            };
        ```

     - 특징
       - 클래스명과 동일한 이름의 public memeber function
       - return type 의 선언이 빠져있음
       - 객체 생성시 딱 1번 자동으로 호출
       - overloading / argument default value 지정 모두 가능
     - 주의사항
       - input 없이 생성&초기화 할 때, `myClass test();` 가 아닌 `myClass test;` 로 해야됨. 함수 prototype 선언과 곂쳐서 컴파일러가 구분을 못 함
     - member initializer
       - Constructor가 호출되면서 동시에 클래스 안의 member 로 존재하는 subClass 를 초기화하거나
       - const 키워드를 가진 member를 초기화하는게 가능
       - member initializer 만으로 초기화를 진행하고, Constructor의 내부는 비워두는게 좋은 습관?
   - Destructor
     ``` c++
        class Name
        {
        private:
            int length;
            char* name;
        public:
            Name(char* name)
            {
                length = strlen(name);
                name = new char[length];
            }
            ...
            ~Name()
            {
                delete []name;
            }
        };
      ```
     - 특징
       - object가 소멸될 때(object가 local에서 선언되었고, 해당 scope에서 빠져나가면, stack에서 소멸됨) 자동으로 실행됨
       - 무조건 `~<클래스명> (void) { ... }` 의 형태
       - return type 의 선언이 빠져있음
       - input type이 void로 고정되어 있기에 overloading, default value 지정 모두 불가
     - 용도
       - member를 포인터로 정의하고, 실제 member 의 선언은 constructor에서 new 키워드를 이용한 동적할당으로 생성
       - Destructor에서는 Constructor에서 동작할당한 member를 delete

## 4-4 Class 배열 & This pointer
  - 클래스 배열 선언 2가지 방식
    - 직접 배열로 선언
      - `myClass test[10];`
      - input이 void인 constructor가 무조건 실행되기 때문에, 미리 정의해두어야 함 
      - 다른 형태의 constructor 사용 불가
      - 별도의 initiation function 을 만들어 사용
    - 포인터로 선언
      - `myClass *temp[10]; ... for  {temp[i] = new myClass(input);}`
      - 반복문을 이용해 동적할당
  - This pointer
    - 클래스 안에서 object 자신의 주소값을 지님
    - 용도 1 : 매개변수와 멤버변수의 이름을 동일하게 사용 할수있게
      ``` c++
        myClass
        {
        private:
            int num;
        public:
            myClass(int num)
            {
                this->num = num;
            }
        }
      ```
    - 용도 2 : Self Reference
      ``` c++
        myClass
        {
        private:
            int num;
        public:
            myClass(int num) : num(num) {}
            myClass& add(int num)
            {
                this->num += num;
                return *this;
            }
            myClass& sub(int num)
            {
                this->num -= num;
                return *this;
            }
        }
        
        ...
        
        myClass sum(3); //sum=3
        sum.add(3).sub(1).add(5).sub(1); // sum=3+3-1+5-1
      ``` 