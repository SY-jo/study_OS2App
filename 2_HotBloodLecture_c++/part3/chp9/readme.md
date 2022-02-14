# Chp 9 : Virtual 심화 & 다중상속

## Plain/Virtual method
* Plain case
  * member function 이 포함된 클래스의 메모리에는 method가 포함되어 있지 않다. 
  * method는 c언어에서의 전역함수와 같이 code 영역에 존재하고, 동일한 class의 object들은 동일한 function code를 공유한다.
  * member function의 주소가 컴파일시 결정됨 -> Static Binding
* Virtual Case
  * class안에 virtual method가 존재하면, object 안에는 각 함수의 이름과 주소가 mapping 된 V-table(Virtual table)을 만들어진다. 
  * 이 테이블을 참조하여 method를 실행
  * 실제로 동작하는 함수의 주소가 런타임에 정해진다. -> Dynamic Binding
  

## 다중상속
* C++ 에서 지원은되나, 사용을 자중하는 문법
* 복수의 클래스에서 상속을 받아 ChildClass 를 만드는 것인데, 이 과정에서 곂치는 method 나 member variable이 생기는 등의 문제가 발생할 수 있다캄
* 이에 대한 해결책으로 virtual inheritance를 지원함
  