// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n)
//     {
//         int j=1;
//         while(j<=n-i+1)
//         {
//             cout<<j;
//             j++;
//         }
//         int k=1;
//         while(k<=i-1)
//         {
//             cout<<"*";
//             k++;
//         }
//         int l=1;
//         while(l<=i-1)
//         {
//             cout<<"*";
//             l++;
//         }
//         j=n-i+1;
//         while(j>=1)
//         {
//             cout<<j;
//             j--;
//         }

//         i++;
//     }
// }
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i+1)
        {
             cout<<j;
             j++;
        }
        j=1;
        while(j<=(i-1)*2)
        {
            cout<<"*";
            j++;
        }
        j=n-i+1;
        while(j>=1)
        {
            cout<<j;
            j=j-1;
        }
        cout<<endl;
        i++;
    }
}