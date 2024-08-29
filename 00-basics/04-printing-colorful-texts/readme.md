# Printing colorful texts

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "\033[31mHello, \033[32mcolorful \033[34mworld!\033[0m" << endl;

    return 0;
}
```

- Run the code:

```bash
> $ g++ main.cpp -o main
> $ ./main
```

---

## StackOverflow answer for this question

- [Printing colorful texts in C++](https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal)
