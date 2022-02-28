# Chp 13

## Template
* function 의 기능은 동일한데, 입출형 마다 일일히 function overriding 해야되는 번거러움을 줄여주는 기능
* template 정의에서 `class` 와 `typename`은 동일한 키워드로 사용됨?
* function template 이 사용되는 자료형에 맞춰서 template function(generated function)이 만들어져서 코드에 추가됨. 즉, 생서되는 것은 compile time이기 때문에 성능저하가 없음

## Syntax
``` c++

    template <class T> // 아래 함수 정의에서 T가 결정되지 않은 자료형으로 사용됨
    T Add(T num1, T num2)
    {
        return num1 + num2;
    }

    ...
    float sum = Add<float>(3.5, 2.4); // <typename> 을 이용하여 T의 자료형을 지정해주거나, <>를 생략하면 컴파일러가 적절하게 골라줌. 다만, 명식적으로 type을 적어주는게 좋다캄
    ...
```

## Specialization
* Overriding 비스무리한 역할
* 특정 자료형에 대해서는 별도로 기능이 정의된 함수를 사용하도록 함
* ``` c++
    template<typename T>
    T myCompare(T arg1, T arg2)
    {
        return arg1 > arg2 ? arg1 : arg2;
    }

    template<>
    char* myCompare<char*>(char* arr1, char* arr2)
    {
        return strcmp(arr1, arr2) ? arr1 : arr2; //두 문자열 주소가 아니라  앞글자를 가지고 순서를 정하게 함  
    }
  ```



## Class Template
* class의 definition에도 template를 적용할 수 있음
* syntax 는 function template과 동일한 방식
* 단, Class template를 사용한 header file, source file 분리시에는 주의사항
    1. source 에서 method의 동작을 정의할 때, 여기에도 `template <typename T>`가 들어감
        ``` c++
            //in header
            template <typename T>
            class myClass
            {
                ...
                
                const T GetMember(void) const;
                ...
            }
            ...
            //in source
            template <typename T>
            const T myClass::GetMember(void) const
            {
                return mem;
            }
        ```
    2. main() 의 source file에 myclass의 header를 #include 할 때, source code도 함께 #include 해야됨
        * compile 단계 중 linker 에서 에러가 발생함.
        * template class의 source file 을 compile하는 과정 중에 main.cpp 에서 사용된 자료형으로 myClass<>가 생성되야함. 하지만 compiler는 이 순간에 main.cpp에서 myClass<?> 뭐가 사용됐는지 모름. 때문에 생략하고 .o 가 만들어짐
        * 때문에 최종적인 linker 단계에서, main에서 사용된 myClass<int>를 찾지 못 하게 됨. 
