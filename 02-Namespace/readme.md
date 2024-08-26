# Namespace in C++

- We use `namespace` to group related variables, functions, classes, etc.

- Using namespace, you can define the space or context in which identifiers are defined i.e. variable, method, classes. In essence, a namespace defines a scope.

> - If multiple variables, functions, classes, etc, have the same name, then compiler will not be able to distinguish between them.
> - To solve this problem, we can use namespace.

```cpp
#include <bits/stdc++.h>
using namespace std;

int a = 10;
int a = 20;

int main()
{
    cout << a << endl; # which a?
    return 0;
}
```

- The above code will not compile.
- To solve this problem, we can use `namespace`.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
}

namespace my_namespace_2
{
    int a = 20;
}

int main()
{
    cout << my_namespace_1::a << endl;
    cout << my_namespace_2::a << endl;
    return 0;
}
```

- Now, the code will compile.

---

## Nested Namespace

> A namespace can be nested inside another namespace.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    namespace my_namespace_2
    {
        int a = 10;
    }
}

int main()
{
    cout << my_namespace_1::my_namespace_2::a << endl;
    return 0;
}
```

---

## Anonymous Namespace

- Anonymous namespace is a namespace without a name.
- We can use anonymous namespace to define a scope, or separate a group of variables, functions, classes, etc.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace
{
    int a = 10;
    int b = 20;
}

int main()
{
    cout << a << endl;
    cout << b << endl;
    return 0;
}
```

---

## Nested Anonymous Namespace

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace
{
    namespace
    {
        int a = 10;
        int b = 20;
    }
}

namespace my_namespace_1
{
    namespace
    {
        int a = 10;
        int b = 20;
    }
}

namespace {
    namespace my_namespace_2
    {
        int a = 10;
        int b = 20;
    }
}

int main()
{
    cout << a << endl;
    cout << b << endl;
    cout << my_namespace_1::a << endl;
    cout << my_namespace_1::b << endl;
    cout << my_namespace_2::a << endl;
    cout << my_namespace_2::b << endl;

    return 0;
}
```

- If two namespaces have the same name, then they will be merged into one namespace.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
}

namespace my_namespace_1
{
    int b = 20;
}
```

- the compiler will merge the two namespaces into one namespace.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
    int b = 20;
}
```

---

## `Using Namespace` directive

- We can use `using namespace` to import all the identifiers from a namespace into the current scope.

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
}


int main()
{
    using namespace my_namespace_1;
    cout << a << endl;
    return 0;
}
```

---

## Aliasing namespace

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
    namespace my_namespace_2
    {
        int b = 20;
    }
}

// aliasing namespace
namespace n1 = my_namespace_1;
namespace n2 = n1::my_namespace_2;

int main(){
    cout << n1::a << endl;
    cout << n2::a << endl;
}
```

---

## `inline` directive

- We can use `inline` directive to inline a namespace (call it directly in the current scope).

```cpp
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace_1
{
    int a = 10;
    inline namespace my_namespace_2
    {
        int b = 20;
    }

    // for already inlined namespace, we don't need to use inline keyword again
    namespace my_namespace_2 
    {
        int c = 30;
    }
}

int main()
{
    cout << my_namespace_1::a << endl;
    cout << my_namespace_1::b << endl;
    cout << my_namespace_1::c << endl;
}
```
