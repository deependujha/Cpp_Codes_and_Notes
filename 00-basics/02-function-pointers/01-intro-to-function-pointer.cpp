#include <bits/stdc++.h>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    auto my_add = add;
    // auto ==> int (*my_add)(int, int)
    // int (*my_add)(int, int) = add;

    cout << my_add(2, 3) << endl;
    return 0;
}