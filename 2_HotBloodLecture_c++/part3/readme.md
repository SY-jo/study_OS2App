# Chp 8 : 다형성(Polymorphism)

## Object Pointer \w ChildClass
* ParentClass 의 pointer 는 상속을 직간접적으로 받는 하위 ChildClass를 모두 가르킬 수 있음
* 이러한 특성 덕분에 프로그램 내부의 Handler 코드의 변경 없이도, 추가되는 새로운 class 들을 관리할 수 있음
  * ex : 술 관리 프로그램. 새롭게 Hendricks gin 을 추가하고자 함. `class Hendricks : public gin { }` 과 같이 상속을 받으면, gin class 를 관리하던 handler를 그대로 사용할 수 있음

## Function Overriding
* ChildClass 안에서 ParentClass 안에 있던 method를 새롭게 정의하는 것
* ex 
  * WildTurkey와 이를 상속 받은 RyeWildTurkey
  * `WildTurkey::ShowIngredients()` 와  `RyeWildTurkey::ShowIngredients()` 가 별도의 출력을 가지도록 하는게 가능함
  * handler 측에서는 `sWhiskey[WHISKEY_NAME]->ShowIngredients()` 의 호출을 동일하게 가져가면서, 실제 출력에 사용되는 method를 object마다 다르게 가져가는게 가능해짐
  * 다만 위와 같이 handler를 쓰기 위해서는 method가 virtual function으로 정의되어 있어야함

## Virtual Function
* "C++ 컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다."
* Function Overriding 의 기능이 의도하는바를 제대로 쓰기 위해서는 method를 정의할 때 `virtual mMethod() { }` 와 같이 해야함
* 오버라이딩되는 함수가 virtual function으로 정의되면, ParentClass의 포인터를 통해 `ptrParrent->mMethod()` 와 같이 호출했을 때, ChildClass의 mMethod를 call하는게 가능해짐

## Abstract Class(추상 클래스)
* Pure Virtual Function 을 method로 가지는 class
  * Pure Virtual Function 은 definition이 비어있는 virtual method
  * `virtual int myMethod(void) = 0;`
* 그 자체로 object를 생성하기 위해서보다, ChildClass에 대한 통일된 규격을 제공하는 용도로 사용됨
  * ex : Spirit class 는 이것 자체로만으로는 object를 생성하지 못 하지만, ChildClass 인 Gin, Whiskey, Rum 등의 공통된 member, method를 담아낼 수 있음. Spirit class 는 하위 클래스들을 찍어내기 위한 일종의 틀
* Abstract Class 를 이용해 object를 생성하려고하면 컴파일러 에러