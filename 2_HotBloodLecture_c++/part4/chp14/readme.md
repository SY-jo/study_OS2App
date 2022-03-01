# Chp 14

## Class template Specialization
* class template 또한 특정 자료형에 대해서 별도의 definition을 지정하는게 가능
* syntax는 function template 와 동일. chp13 참고

## Template 매개변수
* template 인자를 정의할 때, 변수를 넣는게 가능
* ``` c++
      template <typename T, int  len>
      class myClass
      {
      private:
        T arr[len]; //myClass<int, 3> , myClass<double, 7> 등의 generated class 가 가능해짐
        ...
      }
    ```
* Constructor를 사용해서 충분히 기능을 대체할 수 있지만, 서로 장단점이 있다캄

## Static Variable in Generated Class
* class template 안에 static variable을 넣으면, 동일한 class끼리 공유함
* myClass<int> 와 myClass<float> 이 공유하는 static variable은 별개의 것으로 존재.