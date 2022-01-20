#include <iostream>

using namespace std;

typedef struct __Point
{
    int xpos, ypos;
} Point_t;

Point_t& Point_Adder(const Point_t &p1, const Point_t &p2);

int main(void)
{
    Point_t *p1 = new Point_t;
    p1->xpos = 3;
    p1->ypos = 3;

    Point_t *p2 = new Point_t;
    p2->xpos = 1;
    p2->ypos = -1;

    Point_t &p3 = Point_Adder(*p1, *p2);
    
    cout << "x = " << p3.xpos << endl;
    cout << "y = " << p3.ypos << endl;

    delete p1, p2, p3;
}

Point_t& Point_Adder(const Point_t &p1, const Point_t &p2)
{
    Point_t *p = new Point_t;
    
    p->xpos = p1.xpos + p2.xpos;
    p->ypos = p1.ypos + p2.ypos;

    return *p;
}