# Chp 5 : Copy Constructor

## 5 - 1 : Copy constructor 소개
- ``` c++
        class myClass
        {
        private:
            int num;
        public:
            myClass(int _num) : num(_num) {}
        }

        myClass sample = myClass(3);
        myClass sample2 = sample // <==>  myClass sample2(sample)
  ```         
- 위와 같은 대입연산은 `myClass(&myClass copy) : num(copy.num) {}` 의 Constructor 를 사용한 것으로 치환됨
- 근데 위와 같은 constructor 를 정의해두지 않아도 컴파일러가 default로 생성해서 사용함
- explicit 키워드를 사용하여 copy constructor 를 정의하면 `explicit myClass(&myClass copy) : num(copy.num) {}` 위와 같은 묵시적 형변환이 일어나지 않음

## 5 - 2 : Deep copy
- 컴파일러에 의해 삽입되는 default copy constructor 는 단순히 member variable의 값을 복붙하기만함("Shallow Copy").
- 이는 constructor가 heap memory에서 동적할당을 받아오는 class 인 경우에는 문제가 될 수 있음, destructor에서 delete[] 를 호출하니까
- 따라서 `myClass(&myClass copy) : num(copy.num) { name = new char[strlen(copy.name)]; strcpy(name, copy.name); }`와 같은 형태로 Copy constructor를 명시적으로 정의 하고, 동적할당이 필요한 멤버는 new 로 생성해서 내용물만 복붙해가도록 해야함("Deep Copy") 

## 5 - 3 : 효율적인 copy constructor 사용
- Copy constructor 가 호출되는 경우는 크게 3가지
    1. 기존에 생성된 object를 이용해 새로운 object 초기화
    2. **Call-by-value 로 object를 전달하는 경우**
    3. 함수의 return type으로 class reference가 아닌 object 를 하는 경우
- function 의 argument로 어떤 object의 property가 필요한 경우라면, 참조자를 활용한 Call-by-reference 를 해야지 무의미한 메모리 낭비를 방지할 수 있음
    - ./sample/ReturnObjDeadTime.cpp 예시코드 참고. line 29 func()의 입력 argument type을 바꿈으로 인해, 전체 코드에서 object가 생성되는 횟수가 줄어듬


