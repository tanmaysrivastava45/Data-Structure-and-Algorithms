#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool isprime=1;
    for(int i=2;i<n;i++)
    { 
        if(n%i==0)
        {
          isprime=0;
          break;
        }

    }
    if(isprime==0)
    {
        cout<<"it is not a prime no.";

    }
    else{
        cout<<"it is a prime no.";
    }
}   