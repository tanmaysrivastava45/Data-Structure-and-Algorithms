#include<iostream>
using namespace std;

int fibonacci(int s,int e)
{
    int a=s;
    int b=e;
    if(e>20)
    {

        return s;
    }
    s=b;
    e=a+b;
    return fibonacci(s,e);
}

int main()
{
    int s=0;
    int e=1;
    fibonacci(s,e);
}