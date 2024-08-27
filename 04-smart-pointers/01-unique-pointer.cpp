#include <iostream>
#include <memory>
using namespace std;

class A{
    int x;

public:
    A(int x){
        this->x = x;
        cout << "A constructor" << endl;
    }
    ~A(){
        cout<<"A destructor"<<endl;
    }

    void print(){
        cout<<"A::print() called and x = "<<x<<endl;
    }
};

int main()
{
    // unique_ptr<A> a(new A(5));
    unique_ptr<A> a = make_unique<A>(5); // same as above

    a->print();

    // unique_ptr<A> b = a; // will raise error (no copy allowed)

    // but move is allowed
    unique_ptr<A> b = move(a);
    cout<<"--------- after move ----------"<<endl;
    // a->print(); // will raise segmentation fault
    b->print();


    return 0;
}