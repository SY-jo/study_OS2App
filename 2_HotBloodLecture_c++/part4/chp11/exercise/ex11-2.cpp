#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos);
    friend ostream& operator<<(ostream& os, const Point* pos);

};

ostream& operator<<(ostream& os, const Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
}
ostream& operator<<(ostream& os, const Point* pos)
{
    os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
}

typedef Point* Point_PTR;

class BoundCheckPointArray
{
private:
    Point_PTR* arr;
    int arrlen;

    BoundCheckPointArray(const BoundCheckPointArray&) {}
    BoundCheckPointArray& operator=(const BoundCheckPointArray&) {}
public:
    BoundCheckPointArray(int len) : arrlen(len)
    {
        arr = new Point_PTR[len];
    }
    ~BoundCheckPointArray()
    {
        delete[] arr;
    }

    Point_PTR& operator[](const int idx)
    {
        if(idx<0 || idx>=arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    Point_PTR operator[](const int idx) const
    {
        cout << "const" << endl;
        if(idx < 0 || idx>=arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrlen() const
    {
        return arrlen;
    }
};

int main(void)
{
    BoundCheckPointArray arr(3);
    arr[0] = new Point(1, 2);
    arr[1] = new Point(3, 4);
    arr[2] = new Point(5, 6);

    for(int i = 0; i < arr.GetArrlen(); i++)
        cout << arr[i] << endl;
    
    delete arr[0];
    delete arr[1];
    delete arr[2];

    return 0;
}