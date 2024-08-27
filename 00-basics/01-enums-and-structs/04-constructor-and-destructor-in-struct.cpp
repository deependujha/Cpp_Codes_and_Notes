#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {
        cout << "constructor called" << endl;
    }
    ~Point() {
        cout << "destructor called" << endl;
    }

    void distanceFromOrigin() {
        cout << "distance from origin: " << sqrt(x * x + y * y) << endl;
    }
}p1(1, 2), p2(3, 4);

int main()
{
    Point p(1, 2);
    p.distanceFromOrigin();

    p1.distanceFromOrigin();
    p2.distanceFromOrigin();
    return 0;
}