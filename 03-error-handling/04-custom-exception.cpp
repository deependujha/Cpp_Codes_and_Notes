#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
    MyException(string msg) : msg(msg) {}
    const char *what() const throw()
    {
        return msg.c_str();
    }

private:
    string msg;
};

int main()
{
    int a = 10;
    int b = 0;
    try
    {
        if (b == 0)
        {
            throw MyException("Division by zero");
        }
        int c = a / b;
    }
    catch (MyException e)
    {
        cerr << "MyException occurred: " << e.what() << endl;
    }
    return 0;
}
