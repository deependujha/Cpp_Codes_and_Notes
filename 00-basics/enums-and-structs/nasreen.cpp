#include <bits/stdc++.h>
using namespace std;

class MyClass
{

public:
    MyClass()
    {
        cout << "Constructor called" << endl;
        this->data = new int[100]; // Allocate memory for an array
    }

    ~MyClass(){
        cout << "Destructor called" << endl;
        delete[] this->data; // Free the memory
    }

private:
    int *data;
};

int main()
{
    while (true)
    {
        MyClass *obj = new MyClass();
        // Use the object...

        delete obj; // Destructor will be called, freeing the memory
    }
    return 0;
}