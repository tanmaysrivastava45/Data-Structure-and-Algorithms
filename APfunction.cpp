#include<iostream>
using namespace std;

int nthterm(int n)
{
    return (3*n+7);
}

int main()
{
    int n;
    cout<<"enter the first number of your AP";
    cin>>n;
    cout<<"the n th term of your AP is: "<<nthterm(n);
}