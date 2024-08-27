#include <bits/stdc++.h>
using namespace std;

class LeakingClass{
private:
    int *ptr;

public:
    LeakingClass(int n){
        ptr = new int[n];
        cout << "constructor called" << endl;
    }

    ~LeakingClass(){
        cout << "destructor called" << endl;
        delete[] ptr; // comment this line to see the memory leak
    }
};

int main()
{
    while(true){
        LeakingClass* l = new LeakingClass(1000);
        delete l; // comment this line to see the memory leak
    }
        return 0;
}