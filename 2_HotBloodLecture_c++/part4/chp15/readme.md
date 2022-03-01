# Chp 15

## Exception Handling
* 예외란 언어의 문법적인 에러가 아닌, 프로그램 흐름상의 에러. 따라서 컴파일 단계에서 발견되지 않음
* ex : divide(double nom, double den) 의 argument로 den = 0 이 들어오는 경우
* C 에서는 if-else문을 이용해서 예외처리를 했었음. 이로인해 어떤 block이 정사적인 흐름이고 어디가 예외처리 block 인지 한 눈에 들어오지 않음
* C++ 에서는 별도의 예외처리용 문법이 제시됨


## try, throw, catch
* try block 안에서 exception이 throw 되면, catch block 이 실행됨

  ``` c++
      #include <iostream>

      using namespace std;

      void PositiveNumChecker(int num) throw(int, char) // function prototype에 어떤 자료형의 exception 이 throw되는지 명시
      {
          if(num < 0)
              throw -1; //function 안에서 throw가 사용되면, function을 call한 block으로 exception 값이 던져짐
          if(num == 0)
              throw 'z'; 

          cout << "No Exception Detected!" << endl;
      }

      int main(void)
      {
          int num;
          cout << "Insert Positive Number : "; cin >> num;

          while(1)
          {
              try
              {
                  PositiveNumChecker(num);
                  break;
              }
              //try-catch 는 if-else처럼 구문 사이에 다른 명령어가 끼면 안 됨
              catch(int err)
              {
                  cout << "Wrong!" << endl;
                  cout << "Re-Insert Positive Number : "; cin >> num;
              }
              catch(char err) // 여러 자료형의 exception throw될 수 있고, 해당되는 자료형의 catch bloack 이 실행됨
              {
                  cout << "Zero Wrong!" << endl;
              }
          }
      }
  ```

* 명시되지 않은 exception이 throw됐을 때는, default로 `unexpected()` 라는 function이 call되고 프로그램을 종료시킨다캄
* exception 으로 class 를 던지는 것 또한 가능 -> STL에서는 별도로 Exception class 를 제공함
* new 를 이용해 동적할당할 때, 메모리공간이 부족하면 bad_alloc 이라는 exception class를 throw. 이를 쓰기 위해선 #include <new>
* 아래와 같이 catch(...)으로 쓰면, 모든 예외를 여기서 처리하게됨
  ``` c++
        try
        {
            // function
        }
        catch(...)
        {
            //exception handle
        }
```