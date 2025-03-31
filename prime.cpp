#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=2;
    while(i<=n)
    {
     if (n%i!=0)
     {
       cout<<"It is a prime no."<<endl;
       i=i+1;
     }
     else{
        cout<<"It is not a prime no."<<endl;
     }
     return 0;
    }
}