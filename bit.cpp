// #include<iostream>
// #include<math.h>
// using namespace std;
// int main()
// {
//   int n;
//   cin>>n;
//   int ans=0;
//   int i=0;
//   while(n!=0)
//   {
//     int bit = n&1;
//     ans= (bit*pow(10,i))+ans; ///the problem in this code is that pow introduces floating variable and is responsible for precision issues
//     n=n>>1;
//     i++;
//   }
//   cout<<"answer "<<ans;

// }
//let's use another code in that case.


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string binary="";//i used string because of the floating point error in previous code
    if(n==0)
    {
        binary="0";
    }
    else{
        while(n!=0)
        {
            int bit=n&1;//it will take the least significant bit(it means the right most bit ) among them like (5--> 101) and (1-->001) here 5&1 - 1
            binary = to_string(bit) + binary ;//it is type of formula --> ""= "1"+"";
            n=n>>1;//purpose of this is to divide n by 2 and return the remainder as n;
        }
        
    }
    cout<<binary ;
    return 0 ;
}