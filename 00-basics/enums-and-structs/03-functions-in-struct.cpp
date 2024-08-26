#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;

    void init(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    static int getX(Point p)
    {
        return p.x;
    }
};

int main()
{
    Point p;
    p.init(1, 2);
    cout << Point::getX(p) << endl;
    return 0;
}