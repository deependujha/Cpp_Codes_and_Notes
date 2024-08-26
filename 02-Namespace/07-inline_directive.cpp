#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
    inline namespace my_namespace_2
    {
        int b = 20;
    }

    // for already inlined namespace, we don't need to use inline keyword again
    namespace my_namespace_2
    {
        int c = 30;
    }
}

int main()
{
    cout << my_namespace_1::a << endl;
    cout << my_namespace_1::b << endl;
    cout << my_namespace_1::c << endl;
}
