// #include<iostream>
// using namespace std;

// int power()
// {
//   int a,b;
//   cin>>a>>b;
//   int ans=1;
//   for(int i=1;i<=b;i++)
//   {
//     ans=ans*a;
//   }
//   return ans;
// }

// int main()
// {
//     // int a ,b;
//     // cin>>a>>b;
//     // int ans=1;
//     // for(int i=1;i<=b;i++)
//     // {
//     //     ans=ans*a;
//     // }
//     // cout<<ans;

//  cout<<power();
// }

//<-------------------------------------------------------------------------------------------------------------------->

// even - odd function
#include <iostream>
using namespace std;
bool isEven(int n)
{

  if (n & 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}
int main()
{
  int i;
  cin >> i;
  if (isEven(i))
  {
    cout << "this number is even number" << endl;
  }
  else
  {
    cout << "this number is odd number " << endl;
  }
}