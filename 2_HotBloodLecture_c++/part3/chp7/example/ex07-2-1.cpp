#include <iostream>

using namespace std;

class Rectangle
{
private:
    int row;
    int col;
public:
    Rectangle(int _row, int _col)
        : row(_row), col(_col)
    { 
    }
    void ShowAreaInfo(void)
    {
        cout << "Area : " << row * col << endl;
    }
    
};

class Square : public Rectangle
{
public:
    Square(int _row)
        : Rectangle(_row, _row)
    {
    }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}