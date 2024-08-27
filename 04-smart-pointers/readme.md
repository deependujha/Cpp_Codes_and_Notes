# Smart Pointers

- **`Don't need to use new/delete`**

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

---

## Tips

> @peligros13's youtube comment on `https://www.youtube.com/watch?v=UOB7-B2MfwA&t=39s`
>
> A bit late but after listening to several experts, it seems that the authors of the standard and the guidelines are VERY clear about when to use raw or smart pointers. I'll try to summarize them.

1. NEVER use new or delete. It has to be very clear wether a pointer owns the object or doesn't. If it owns the object (for example, it is creating the object), use a smart pointer and make_unique or make_shared.

2. By default, use unique_ptr because it has almost no overhead. If you know it will need to have several owners, use shared_ptr.


3. When the pointer will not own the object, use raw pointers. For example, when passing an object to a function, the pointer that receives it will not own the object (it will still be alive once the function returns), so don't pass the smart pointer, pass a raw pointer.
To pass a unique_ptr as a raw pointer to a function, the best way is to dereference it and pass it by reference. So the function is just for example "void foo(const Class& myObject)", and you call it with "foo(*myPointer)".
Another way would be to pass the adress itself, with the method "unique_ptr.get()".

4. Again, never use delete on a raw pointer and assume it does not own the object.

5. When you create an object inside a function and want to return it, do it as a unique_ptr. The receiver will be able to do whatever they want with it. Keep in mind that now, passing a local object from a function by copy will not actually copy it, but move it as an r-value. So it will move into the new unique_ptr, without a compiler error. Again, the receiver can do whatever they want, so they can move it into a shared_ptr or even a raw pointer.

6. When you want to transfer ownership of a unique_ptr, you can do it as a r-value using std::move(). This is basically what I just explained that C++ does when returning from a function. You can do it to transfer the ownership to a function.

These are the basic guidelines with which you will probably never have memory leaks or loose pointers.
