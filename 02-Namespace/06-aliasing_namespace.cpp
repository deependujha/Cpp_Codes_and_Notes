#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
    namespace my_namespace_2
    {
        int b = 20;
    }
}

// aliasing namespace
namespace n1 = my_namespace_1;
namespace n2 = n1::my_namespace_2;

int main()
{
    cout << n1::a << endl;
    cout << n2::b << endl;
}
