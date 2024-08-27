#include <bits/stdc++.h>
using namespace std;

void forEach(vector<int> v, void (*f)(int))
{
    for (auto i : v)
    {
        f(i);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    forEach(v, [](int i)
            { cout << "value: " << i << endl; });
    return 0;
}