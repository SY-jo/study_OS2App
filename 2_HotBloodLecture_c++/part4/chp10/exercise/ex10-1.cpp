#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int _x, int _y) : x(_x), y(_y) { };
    
    Point operator+(const Point& ref) const
    {
        Point result(x+ref.x, y+ref.y);
        return result;
    }

    friend Point operator-(const Point, const Point);

    Point operator+=(const Point& ref)
    {
        x += ref.x;
        y += ref.y;
        
        return *this;
    }

    Point operator-=(const Point& ref)
    {
        x -= ref.x;
        y -= ref.y;
        
        return *this;
    }

    friend bool operator==(const Point, const Point);
    friend bool operator!=(const Point, const Point);

    void GetPos(void)
    {
        cout << "[" << x << ", " << y << "]" << endl;
    }
};

Point operator-(const Point pos1, const Point pos2)
{
    Point result(pos1.x - pos2.x, pos1.y - pos2.y);
    return result;
}

bool operator==(const Point pos1, const Point pos2)
{
    if(pos1.x == pos2.x)
        if(pos1.y == pos2.y)
            return true;
    return false;
}

bool operator!=(const Point pos1, const Point pos2)
{
    return !(pos1 == pos2);
}

int main(void)
{
    Point pos1(1, 1);
    Point pos2(2, 2);

    Point pos3 = pos1 + pos2;
    Point pos4 = pos1 - pos2;

    pos3.GetPos();
    pos4.GetPos();
    
    pos1 += pos2;
    pos1.GetPos();
    pos1 -= pos2;
    pos1.GetPos();

    cout << (pos1 == pos2) << endl;
    cout << (pos1 != pos2) << endl;

    return 0;
}