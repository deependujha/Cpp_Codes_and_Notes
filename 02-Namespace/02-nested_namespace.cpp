#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    namespace my_namespace_2
    {
        int a = 10;
    }
}

int main()
{
    cout << my_namespace_1::my_namespace_2::a << endl;
    return 0;
}