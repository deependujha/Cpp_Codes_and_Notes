#include <bits/stdc++.h>
using namespace std;

void forEach(vector<int> v, void (*f)(int)) // function pointer
{
    for (auto i : v)
    {
        f(i);
    }
}

void printVal(int i)
{
    cout << "value is: " << i << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    forEach(v, printVal);
    return 0;
}