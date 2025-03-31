// #include<iostream>
// #include<math.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int ans=0;
//     int i=0;
//     while(n!=0)
//     {
//         int bit = n & 1;
//         ans = (bit * pow(10,i))+ans;
//         n=n>>1;
//         i++;
//     }
//     cout<<ans;
// }


#include<iostream >
using namespace std;
int main()
{
    int n;
    cin>>n;
    string binary ="";
    if( n==0)
    {
        binary="0";

    }
    else{
        while(n!=0)
        {
            int bit = n&1;
            binary = binary + to_string(bit);
            n=n>>1;
        }
           
    }
    cout<<binary;
}
