#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a = 10;
    int b = 0;
    try
    {
        if (b == 0)
        {
            throw "Division by zero";
        }
        if (b == 1)
        {
            throw 1;
        }
        if (b == 2)
        {
            throw runtime_error("Division by zero");
        }
        int c = a / b;
    }
    catch (const char *e)
    {
        cerr << "Exception occurred with char*: " << e << endl;
    }
    catch (const int e)
    {
        cerr << "Exception occurred with int: " << e << endl;
    }
    catch (...) // catch all remaining exceptions
    {
        cout << "Exception occurred with unknown type" << endl;
    }
    return 0;
}
