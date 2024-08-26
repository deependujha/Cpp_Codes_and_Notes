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
            throw runtime_error("Division by zero");
        }
        int c = a / b;
    }
    catch (runtime_error e)
    {
        cerr << "Exception occurred: " << e.what() << endl;
    }
    return 0;
}