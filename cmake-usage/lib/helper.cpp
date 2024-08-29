# include<iostream>

int sum(int a, int b)
{
    std::cout<<"I am a sum function in a library"<<std::endl;
    return a + b;
}

int multiply(int a, int b)
{
    std::cout<<"I am a multiply function in a library"<<std::endl;
    return a * b;
}