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