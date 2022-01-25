#ifndef POINT_H_
#define POINT_H_

#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y);
    void ShowPointInfo(void) const;
};


class Circle
{
private:
    Point center;
    int radius;
public:
    Circle(int x, int y, int r);
    void ShowCircleInfo(void) const;
};


class Ring
{
private:
    Circle inner;
    Circle outter;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2);
    void ShowRingInfo(void) const;
};


#endif /* POINT_H_ */

