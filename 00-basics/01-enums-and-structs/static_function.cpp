#include <bits/stdc++.h>
using namespace std;

void static_function(){
    static int a = 10;
    cout << a << endl;
    a++;
}
int main()
{
    for(int i = 0; i < 10; i++){
        static_function();
    }
    return 0;
}