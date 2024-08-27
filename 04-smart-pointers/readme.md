# Smart Pointers

- Smart pointers are a type of pointer that automatically manages the lifetime of the object it points to.
- In normal pointers, the programmer is responsible for deleting the object when it is no longer needed.
- Smart pointers automatically delete the object when it is no longer needed, which can save a lot of code. (whenever the reference count reaches zero, the object is deleted)
- available in `memory` header after C++11

## Types of Smart Pointers

- Unique pointers:
  - Only one reference to the object exists.
  - The object is deleted when the last unique pointer goes out of scope.
  - Can't be copied.
  - `make_unique` is used to create a unique pointer.
- Shared pointers:
  - Multiple references to the object exist.
  - The object is deleted when the last shared pointer goes out of scope.
  - Can be copied.
  - `make_shared` is used to create a shared pointer.
- Weak pointers:
  - Multiple references to the object exist.
  - Doesn't increase the reference count when copied.
  - Can be copied.
  - Can be null.
  - `make_shared` is used to create a weak pointer.

---

## Unique Pointers

```cpp
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
```

---

## Shared Pointers

```cpp
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
        shared_ptr<A> a;
        {
            shared_ptr<A> b = make_shared<A>(5);
            cout << "count of ptr: " << b.use_count() << endl;
            cout << "====================================" << endl;
            a = b; // copy
            b->print();
            cout<<"count of ptr: "<<b.use_count()<<endl;
        } // b goes out of scope, but the destructor is not called (reference count is still 1)
        cout << "====================================" << endl;
        a->print();
        cout << "count of ptr: " << a.use_count() << endl;
    }
    return 0;
}
```

---

## Weak Pointers

```cpp
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
        weak_ptr<A> a;
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
```
