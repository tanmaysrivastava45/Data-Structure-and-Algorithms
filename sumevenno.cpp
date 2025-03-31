#include<iostream>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    int i=0;
    sum=0;
    while(i<=n)
    {
      sum=sum+i;
      i=i+2;
      
    }
    cout<<sum;
}