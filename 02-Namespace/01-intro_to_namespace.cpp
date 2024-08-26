#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
}

namespace my_namespace_2
{
    int a = 20;
}

int main()
{
    cout << my_namespace_1::a << endl;
    cout << my_namespace_2::a << endl;
    return 0;
}