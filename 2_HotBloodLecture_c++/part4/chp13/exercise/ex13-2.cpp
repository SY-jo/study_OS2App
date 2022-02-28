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
    
    void ShowPosition(void) const
    {
        cout << xpos << ", " << ypos << endl;
    }
    void SetPosition(int _xpos, int _ypos)
    {
        xpos = _xpos; ypos = _ypos;
    }
};

template <typename T>
class SmartPtr
{
private:
    T* posptr;
public:
    SmartPtr(T* ptr) : posptr(ptr) {}
    T& operator*() const { return *posptr; }
    T* operator->() const { return posptr; }
    ~SmartPtr() { delete posptr; }
};

int main(void)
{
    SmartPtr<Point> sptr1(new Point(1,2));
    SmartPtr<Point> sptr2(new Point(3,4));
    
    sptr1->ShowPosition();
    sptr2->ShowPosition();

    sptr1->SetPosition(5,6);
    sptr2->SetPosition(7,8);

    sptr1->ShowPosition();
    sptr2->ShowPosition();

    return 0;
}

