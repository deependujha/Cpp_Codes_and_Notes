# Enums & Structs

## Enums

- if you have a finite set of values, use an enum instead of using a number and remembering what each number means
- for example, if you have a set of days of the week, you can use an enum to represent that, instead of using numbers from (0-6)
- enums are a type of data structure that is used to define a set of named constants

```cpp
#include <bits/stdc++.h>
using namespace std;

enum LogLevel : unsigned int // define datatype (can be any integer type)
{
    DEBUG, // 0
    ERROR, // 1
    INFO,  // 2
    WARNING // 3
};

int main()
{
    LogLevel level = DEBUG;
    cout << level << endl;

    LogLevel level2 = LogLevel::INFO;

    cout << level2 << endl;
    return 0;
}
```

---

## Structs

- structs are a way to group related data together
- they are useful when you want to create a custom data type that has multiple fields
- structs are defined using the `struct` keyword

```cpp
# include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
};

int main()
{
    Point p = {1, 2};
    cout << p.x << " " << p.y << endl;
    return 0;
}
```

---

## Functions in Structs

- functions can be defined inside structs
- they can be used to access the fields of the struct
- functions can be defined with the `static` keyword to make them accessible outside of the struct

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;

    void init(int x, int y){
        this->x = x;
        this->y = y;
    }
    static int getX(Point p)
    {
        return p.x;
    }
};

int main()
{
    Point p;
    p.init(1, 2);
    cout << Point::getX(p) << endl;
    return 0;
}
```

---

## Constructor and Destructor in Structs

- constructors and destructors are special functions that are called when an object is created and destroyed, respectively
- they are defined inside the struct
- **Constructors** => Same name as the struct
- **Destructors** => Same name as the struct, but with an extra `~` at the start

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {
        cout << "constructor called" << endl;
    }
    ~Point() {
        cout << "destructor called" << endl;
    }

    void distanceFromOrigin() {
        cout << "distance from origin: " << sqrt(x * x + y * y) << endl;
    }
};

int main()
{
    Point p(1, 2);
    p.distanceFromOrigin();
    return 0;
}
```

---

## Initializer List

- initializer lists are a way to initialize the fields of a struct
- they are defined using the `:` operator
- they are useful to separate the initialization code from the main constructor body to **help developers focus on what special functionality the constructor provides rather than the boilerplate code**

```cpp
struct Point
{
    int x;
    int y;

    // below `: x(x), y(y)` is the initializer list

    Point(int x, int y) : x(x), y(y) {}
};
```

---

## Creating instances of Structs with Struct declarations

```cpp
struct Point
{
    int x;
    int y;

    // below `: x(x), y(y)` is the initializer list
    Point(int x, int y) : x(x), y(y) {}

}p1(1,2), p2(3,4);
// p1 and p2 are instances of the Point struct
```
