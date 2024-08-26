#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a = 10;
    int b = 0;
    try
    {
        if(b==0)
        {
            throw "Division by zero";
        }
        int c = a / b;
    }
    catch (const char *e)
    {
        cerr << "Exception occurred: " << e << endl;
    }
    return 0;
}