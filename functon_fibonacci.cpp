#include<iostream>
using namespace std;

int printnum(int n)
{
    int a=0;
    int b=1;
    int ans;
    if(n==1)
    {
        return ans=0;
    }
    if (n==2)
    {
        return ans=1;
    }
    for(int i=1;i<=n-2;i++)
    {
       int c=a+b;
        a=b;
        b=c;
        ans=c;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<printnum(n);
}