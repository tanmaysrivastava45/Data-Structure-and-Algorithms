#include<iostream>
using namespace std;

int gcd(int x,int y)
{
  if(y==0)
  return x;
  else{
    return gcd(y,x%y);
  }
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"gcd of "<<a<<" and "<<b<<" is : "<<gcd(a,b);
}