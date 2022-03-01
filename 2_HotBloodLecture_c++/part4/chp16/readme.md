# Chp 16

## C의 typecast
* C와의 호환성을 위해, C++에서도 C에서 쓰던 typecast를 사용할 수 있음
* 다만, C의 typecast 는 가능한 기능의 범위가 너무 넓게 잡혀있어서 컴파일 에러가 거의 안 남.
* C++ 에서는 4가지 종류의 새로운 typecast 제공


## dynamic_cast / static_cast / const_cast / reinterpret_cast
* Syntax : `dynamic_cast<T> (arg)`
  ``` c++
    int num1 = 10; int num2 = 3;
    double result = dynamic_cast<double>(num1) / num2;
    ```
* 연산자이기는 한데, template function 으로 구현되어 있는듯
* 오른쪽 놈일수록 형 변환이 가능한 범위가 늘어남
* dynamic_cast 는 runtime 중에도 exception 을 내는 등 안정성이 뛰어남. 그만큼 느리기도함.
* 기본적으로는 dynamic_cast 사용하되, 실행속도를 높이기 위해 제한된 범위 안에서 static_cast 사용
* const_cast 는 argument의 const 속성을 없애면서 형 변환, reinterpret_cast 는 C의 형 변환가 동일
* Parent Class 와 Child Class 의 각 pointer 사이에서 일어나는 typecast 관련

