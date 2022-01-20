#include <iostream>

void swap(int*, int*);
void swap(char*, char*);
void swap(double*, double*);

int main(void)
{
    int num1 = 10, num2 = 20;
    swap(&num1, &num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'a', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    double dbl1 = 3.14, dbl2 = 2.7;
    swap(&dbl1, &dbl2);
    std::cout << dbl1 << ' ' << dbl2 << std::endl;
}

void swap(int* val1, int* val2)
{
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void swap(char* val1, char* val2)
{
    char temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void swap(double* val1, double* val2)
{
    double temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
