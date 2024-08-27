#include <bits/stdc++.h>
#include <memory>
using namespace std;

class A
{
    int x;

public:
    A(int x)
    {
        this->x = x;
        cout << "A constructor" << endl;
    }
    ~A()
    {
        cout << "A destructor" << endl;
    }

    void print()
    {
        cout << "A::print() called and x = " << x << endl;
    }
};

int main()
{
    {
        weak_ptr<A> a; // weak pointer is used to remove cyclic dependencies between shared_ptr
        {
            shared_ptr<A> b = make_shared<A>(5);
            cout << "count of ptr: " << b.use_count() << endl;
            cout << "====================================" << endl;
            cout<<"a.expired(): "<<a.expired()<<endl;
            a = b; // copy
            b->print();
            cout << "a.expired(): " << a.expired() << endl;

            cout << "count of ptr: " << b.use_count() << endl;
        } // b goes out of scope, but the destructor is not called (reference count is still 1)
        cout << "====================================" << endl;
        cout << "a.expired(): " << a.expired() << endl;

        if(a.expired()==false)a.lock()->print(); // a is not expired, so we can lock it (to safely access the object)
        cout << "count of ptr: " << a.use_count() << endl;
    }
    return 0;
}