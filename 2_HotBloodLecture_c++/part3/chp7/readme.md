## Chp 7 : 상속 basic
* 목적
  * 코드의 재사용
  * 프로그램의 확장성 향상
* 상속을 받은 ChildClass 는 ParentClass 의 member와 method를 함께 가지게 됨.
* Information Hiding in the Inheritance
  * 상속을 받은 ChildClass 라도, Parent 의 privatememeber variable에 접근불가. 
  * 하지만 `protected: ` 접근제어 지시자에 있는 것은 사용가능
  * 상속에서도 정보은닉 특성을 유지하기 위해 가급적이면 사용x
* 용어
  * Upper class <-> Lower class
  * base class <-> Derived class
  * Super class <-> Sub class
  * Parent class <-> Child class
* Child class 의 constructor 에서 Parent class가 언급되지 않으면, 자동으로 void input type의 default constructor of Parent class 가 호출된다.
* 사용법
  ``` c++
    class myChild : public myParent
    {
        ...
    }
  ```
* public/protected/private 상속
  * `class ChildClass : <public/protected/private> ParentClass { }`
  * protected 를 선택했다면, Parent Class 내부의 접근제어 지시자 중 protected 보다 넓은 public이 protected로 바뀌면서 ChildClass에 상속됨.
  * private 를 선택했다면, Parten Class 내부의 접근제어 지시자가 모두 private으로 바뀌어 ChildClass에 상속
  * public 을 선택했다면, 변화없이 그대로 상속
  * **왠만하면 public 상속만을 사용**
  
* Is-A 관계 / Has-A 관계
  * Is-A : Bombay(ChildClass) is a Gin(ParentClass) -> 상속을 이용해 표현
  * Has-A : GinTonic has a Gin -> member class 로써 표현
  * Has-A 관계를 상속을 이용해 표현하는 것 또한 가능하지만, 확장성 측면에서 매우매우매우 별로임

