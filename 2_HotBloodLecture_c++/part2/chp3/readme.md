# Chp 3 : Class 기초

## 3-1 : C++ 에서의 struct
- 프로그램의 구성
  - Data의 표현 + Data의 처리
- Data의 표현 = struct
  - 기본적인 자료형(int, char, float)을 엮어서 상황에 맞는 자료형을 만들어 사용
  - 만들어진 struct 을 입력이나 출력으로 가지는 function(Data의 처리)은 해당 구조체에 종속된다 볼 수 있음
  - 일반적인 다른 data들은 해당 function들을 사용할 일이 없음. 혹은 없도록 만들어야됨
- C++ 에서의 struct
    1. `typedef struct myType { ... } myType_t;` 와 같이 할 필요 없고, `struct myType { ... }` 해두면 `myType element1;`그대로 사용 가능
    2. struct 안에 function 을 넣을 수 있음
        - function의 prototype만 넣고, 정의 밖에서 하는 것도 가능. 단, 이렇게 하면 inline function이 아니게 됨.
    3. struct 안에 enum 을 넣을 수 있음
    4. 사실 몇 가지 세세한 차이를 제외하고는 struct 와 class 는 동일하게 동작한다?
        - class는 내부 변수 및 함수가 default로 private / struct는 default로 public
        - 이거 말고도 차이점이 더 있다카는데, 나중에 뒤 내용들을 공부해야 할 수 있음

## 3-2 : Class and Object   
  - 접근제어 지시자(Access Control Specifier)
    - public : 어떤 곳에서든 접근 가능
    - private : 클래스 안에서만 접근 허용
    - protected : 상속관계에서, 유도 클래스에서의 접근 허용..? (상속은 다다음챕터)
  - Object
    - 현실에 존재하는 어떤 사물이나 대상.
    - 객체는 1. 현재 상태와 2.상태를 변화시키는 행동으로 묘사될 수 있다.
    - member variable/function
  - Object Oriented Programming
    - 대상을 묘사하는 class 를 만들어 사용
      ``` c++
        class Me
        {
        private:
          int hungriness;
          double stressness;

        public:
          void Init(void);
          void eat(Food menu);
          void study(int time);
          void status(void);
          void rest(int time);
        };
      ```
    - 이렇게 해두면 프로그램의 진행(객체의 상태변화와 행동)이 직관적으로 읽혀짐
      ``` c++
        int main(void)
        {
          Me jo;
          // Me * jo = new Me;
          // delete jo;

          jo.Init();

          jo.study(3);
          jo.eat(burger);
          jo.study(10);
          jo.rest(5);

          return 0;
        }
      ```