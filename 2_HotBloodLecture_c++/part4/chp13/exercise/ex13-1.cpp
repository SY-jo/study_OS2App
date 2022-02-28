#include <iostream>

using namespace std;

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point(int x=0, int y=0)
        : xpos(x), ypos(y)
    { }
    
    void ShowPosition(void)
    {
        cout << xpos << ", " << ypos << endl;
    }
};

template <typename T>
void SwapData(T& data1, T& data2)
{
    T temp = data1;
    data1 = data2;
    data2 = temp;
}

template <typename T>
T SumArray(T arr[], int len)
{
    T sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

int main(void)
{
    int a = 1; int b = 2;
    SwapData<int>(b, a);
    cout << "a = " << a << ", b = " << b << endl;

    Point aa(1,2);
    Point bb(3,4);
    SwapData<Point>(bb, aa);
    aa.ShowPosition();
    bb.ShowPosition();

    int arr1[5] = {0, 1, 2, 3, 4};
    float arr2[5] = {0.0, 0.1, 0.2, 0.3, 0.4};
    
    cout << "sum of arr1 = " << SumArray<int>(arr1, 5) << endl;
    cout << "sum of arr2 = " << SumArray<float>(arr2, 5) << endl;

    return 0;
}

