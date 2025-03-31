#include<iostream>
using namespace std;

int main()
{
    int n=10;
    bool isprime=true;
    if(n<=1)
    {
        isprime=false;
    }
    for(int i=2;i<n;i++)
    {
      if(n%i==0)
      {
       isprime=false;
       break;

      }
     
    }
    if (isprime)
    {
        cout<<"p";
    }
    else{
        cout<<"n";
    }
}