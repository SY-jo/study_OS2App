# Chp11

## = overloading
* 대입연산자는 copy constructor와 여러점에서 유사함
  * 별도로 정의를 안 하면, class에 default 대입연산자가 정의됨
  * default 대입연산자는 모든 member variable에 대해 shallow copy 를 수행함
* 객체가 선언과 함께 초기화 되는 경우에 사용된 `=`는 Constructor를 불러오고, 이미 초기화가 된 객체에서 사용된 `=`는 operator= method를 불러온다
* ```c++
    class myClass
    {
    private:
        char* name;
    ...
    myClass& operator=(const myClass& ref)
    {
        ...
    }
    ...
    }
    ...
    myClass src("jo");
    myClass cpy("yun");
    cpy = src; // 여기서 여러 문제 발생
  ```
  * 2가지 이유로 직접 정의가 필요
  1. Deep copy를 해야되니까
  2.  동적할당된 member가 있는 경우, heap memory 를 가르키는 포인터의 값이 수정되기 전에 `delete`을 해줘야됨. Destructor는 현재 가르키고 있는 heap memory에 대해서만 delete함 
* 상속을 받은 ChildClass의 경우 주의사항
    ```c++
        myClass2& operaotr=(const myClass2& ref)
        {
            myClass1::operator=(ref) // 정의 안에 ParentClass의 =연산 method를 포함시켜야 정상적으로 동작. 이게 없으면 ParentClass에 속하는 member variable들은 copy가 안 됨
            ... // 나머지 copy 연산들
        }
    ```
        
## [ ]
* 배열의 인덱스 `arr[0]` 연산자
* 인덱스 연산자의 문제점 중 하나는 Bound Check 를 안 한다는 점. 배열 원소를 벗어난 메모리 공간에도 접근할 수 있다
    * ex
        ``` c
        #include <stdio.h>

        int main(void)
        {
            int arr[3] = {0, 1, 2};

            for(int i = 0; i < 5; i++)
                printf("%d ", arr[i]); // array bound를 벗어난 memory access

            return 0;
        }
        ```
    * 위 코드는 컴파일해도 에러가 발생 안 함
    * 위와 같은 특징을 이용해서 프로그래밍하는 것도 가능하지만, 대부분의 경우 써먹기는 커녕 코딩 실수로 이어지기만함
* [  ] 연산자를 overloading 해서, Bound Check를 if문을 써서 넣을 수 있음
    ``` c++
      Point_PTR& operator[](const int idx)
      {
        if(idx<0 || idx>=arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
      }
    ```
* STL 에서 제공하는 array container 에 위와 같은 특성이 반영되어 있다캄

## new, delete, *(pointer), (pointer)->
* overloading 이 가능하다. 일단 이 정도만 알고있자

## SmartPointer
* Pointer 에 여러가지 기능을 추가한 객체
* pointer의 잘못된 사용으로 인한 memory error 문제를 방지해줌
* 직접 정의하기 보다는 STL 에서 검증된 것을 사용

## Functor?
* ( ) 를 overloading 한 것.
* 이해 실패. 나중에 필요해지면 다시 볼 것.