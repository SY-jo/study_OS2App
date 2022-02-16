#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    // Point():x(0),y(0) {};
    Point(int _x=0, int _y=0) : x(_x), y(_y) { cout << "Constructor called" << endl;}
    
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
    Point operator-(void) const
    {
        Point result(-x, -y);
        return result;
    }
    friend Point operator~(const Point&);

    void GetPos(void)
    {
        cout << "[" << x << ", " << y << "]" << endl;
    }
    void SetPos(int _x, int _y)
    {
        x = _x;
        y = _y;
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

Point operator~(const Point& ref)
{
    Point result(ref.y, ref.x);
    return result;
}

void operator<<(ostream& io, Point& pos)
{
    pos.GetPos();
}

istream& operator>>(istream& io, Point& dst)
{
    int x, y;
    io >> x >> y;
    dst.SetPos(x, y);
    return io;
}

int main(void)
{
    Point pos1;
    cout << "x, y input : ";
    cin >> pos1;
    pos1.GetPos();

    // cout << pos1;

   

    return 0;
}