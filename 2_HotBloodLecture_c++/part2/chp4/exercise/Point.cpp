#include "Point.h"


Point::Point(int x, int y) : xpos(x), ypos(y) { }

void Point::ShowPointInfo(void) const
{
    cout << "[" << xpos << ", " << ypos << "]" << endl;
}


Circle::Circle(int x, int y, int r) : center(x, y), radius(r) { }

void Circle::ShowCircleInfo(void) const
{
    cout << "radius : " << radius << endl;
    center.ShowPointInfo();
}


Ring::Ring(int x1, int y1, int r1, int x2, int y2, int r2) : inner(x1, y1, r1), outter(x2, y2, r2) { }

void Ring::ShowRingInfo(void) const
{
    cout << "Inner Circle Info..." << endl;
    inner.ShowCircleInfo();
    cout << "Outter Circle Info..." << endl;
    outter.ShowCircleInfo();
}
