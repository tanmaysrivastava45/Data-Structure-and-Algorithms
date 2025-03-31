#include<iostream>
using namespace std;

int sqr(int n)
{
 int s=0;
 int e=n;
 int mid=s+(e-s)/2;
 int ans=-1;
 while(s<=e)
 {
    int mul=mid*mid;
    if(mul==n)
    {
        return mid;
    }
    if(mul<n)
    {
        ans=mid;
        s=mid+1;
    }
    else{
        e=mid-1;
    }
    mid=s+(e-s)/2;
 }
 return ans;
}
double precision(int n,int p,int temps)
{
    double factor=1;
    double ans=temps;
    for(int i=0;i<p;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int temps=sqr(n);
    cout<<precision(n,3,temps);
}
// #include<iostream>
// using namespace std;

//  long long int sqrtInteger(int n) {
        
//         int s = 0;
//         int e = n;
//         long long int mid = s + (e-s)/2;
        
//         long long int ans = -1;
//         while(s<=e) {
            
//             long long int square = mid*mid;
            
//             if(square == n)
//                 return mid;
            
//             if(square < n ){
//                 ans = mid;
//                 s = mid+1;
//             }
//             else
//             {
//                 e = mid - 1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return ans;
//     }

// double morePrecision(int n, int precision, int tempSol) {
    
//     double factor = 1;
//     double ans = tempSol;

//     for(int i=0; i<precision; i++) {
//         factor = factor/10;

//         for(double j=ans; j*j<n; j= j+factor ){
//             ans = j;
//         }
//     }
//     return ans;
// }

// int main() {
//     int n;
//     cout <<" Enter the number " << endl;
//     cin >> n;

//     int tempSol = sqrtInteger(n);
//     cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

//     return 0;
// }