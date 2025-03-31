#include<iostream>
using namespace std;

int factorial(int a)
{
    int factorial=1;
    for(int i=1;i<=a;i++)
    {
        factorial=factorial*i;
    }
    return factorial;
}

int nCr(int n,int r)
{
    int num=factorial(n);
    int denom=factorial(r)*factorial(n-r);
    
    return num/denom;
}
int main()
{
    int n;
    int r;
    cin>>n>>r;
    cout<<nCr(n,r);
}