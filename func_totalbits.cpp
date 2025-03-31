// #include<iostream>
// using namespace std;

// int totalbits(int a)
// {
//   int ans=0;
//   if(a==0)
//   {
//     return ans ;
//   }
//   else{
//   while(a!=0)
//   {
//     int bit =a&1;
//     a>>1;
//     return ans=ans+1;
//   }
//   }
//   return ans;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<totalbits(n);
// }

#include<iostream>
using namespace std;

int totalbitsA(int a)
{
    int count =0;
    while(a!=0)
    {
        if(a&1)
        {
            count++;
        }
        a=a>>1;
    }
    return count;
}

int totalbitsB(int b)
{
  int count =0;
  while(b!=0)
  {
    if(b&1)
  {
    count++;
  }
  b=b>>1;
  }
  return count;
}
int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    int ans1 = totalbitsA(n);
    int ans2= totalbitsB(x);
    int totalcount=ans1+ans2;
    cout<<totalcount;
}