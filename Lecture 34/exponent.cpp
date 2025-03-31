#include<iostream>
using namespace std;

int expo(int a,int b)
{
    
    if(b==0)
    {
        return 1;
    }
    int ans = expo(a,b/2);
    if(b%2==0)
    {
      return ans*ans;
    }
    else{
        return a*(ans*ans);
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans = expo(a,b);
    cout<<ans;
}