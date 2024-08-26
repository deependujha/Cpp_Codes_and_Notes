#include <bits/stdc++.h>
using namespace std;

namespace
{
    namespace
    {
        int a = 10;
        int b = 20;
    }
}

namespace my_namespace_1
{
    namespace
    {
        int a = 30;
        int b = 40;
    }
}

namespace
{
    namespace my_namespace_2
    {
        int a = 50;
        int b = 60;
    }
}

int main()
{
    cout << a << endl;
    cout << b << endl;
    cout << my_namespace_1::a << endl;
    cout << my_namespace_1::b << endl;
    cout << my_namespace_2::a << endl;
    cout << my_namespace_2::b << endl;

    return 0;
}