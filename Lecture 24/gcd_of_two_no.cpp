#include<iostream>
using namespace std;

int gcd(int x,int y)
{
 while(x!=y)
 {
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if(x>y)
    {
        x=x-y;
    }
    if(y>x)
    {
        y=y-x;
    }
 }
 return x;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"gcd of a and b is : "<<gcd(a,b)<<endl;
    cout<<"lcm of a and b is : "<<a*b/gcd(a,b);
}