# Passing arguments to C++ binary

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello World!" << endl;
    std::cout << "Have " << argc << " arguments:\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }
    return 0;
}
```

- Run the code:

```bash
> $ g++ main.cpp -o main
> $ ./main hello world my name is Deependu
```
