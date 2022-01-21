#include "Point.h"


void Point::Init(int x, int y)
{
    xpos = x;
    ypos = y;
}

void Point::ShowPointInfo(void) const
{
    cout << "[" << xpos << ", " << ypos << "]" << endl;
}


void Circle::Init(int x, int y, int r)
{
    center.Init(x, y);
    radius = r;
}

void Circle::ShowCircleInfo(void) const
{
    cout << "radius : " << radius << endl;
    center.ShowPointInfo();
}


void Ring::Init(int x1, int y1, int r1, int x2, int y2, int r2)
{
    inner.Init(x1, y1, r1);
    outter.Init(x2, y2, r2);
}

void Ring::ShowRingInfo(void) const
{
    cout << "Inner Circle Info..." << endl;
    inner.ShowCircleInfo();
    cout << "Outter Circle Info..." << endl;
    outter.ShowCircleInfo();
}
