# chp 2
## chp 2-2 : bool type
  - c++ 에서는 bool 자료형이 기본으로 제공됨
  - c 에서는 stdbool.h 필요
  
## chp 2-3 : 참조자reference
  - 변수에 대한 별칭을 만들어 줄 수 있도록 만든 새로운 문법
  - 포인터를 사용하던 Call-by-Reference 를 좀 직관적으로 보이게 만들어줌   
  
    ``` c++
        void myFunc(int &ref)
        {
            ref++;
        }

        ...

        int main(void)
        {
            int num = 0;
            int &num_alias = num;

            myFunc(num);
            cout << num << endl; // 1
            cout << num_alias << endl; // 1
            
            num_alias++;
            cout << num << endl; // 2
            cout << num_alias << endl; // 2
        }
    ```
  - function의 return type을 reference로 하거나, const 키워드를 붙여서 참조는 하되 조작을 못 하게 하거나, 등등 더 다양한 활용법이 있음


## chp 2-5 : 동적할당
  - malloc() 대신 new
  - free() 대신 delete
    
    ``` c
        // in C
        #include <stdlib.h>
        ...
        char* Str = (char*)malloc(sizeof(char) * STR_NUM);
        ...
        free(Str);
    ```
    ``` c++
        // in C++
        char *Str = new char[STR_NUM];
        ...
        delete []Str;
    ```