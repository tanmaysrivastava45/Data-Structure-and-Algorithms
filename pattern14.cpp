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
        char alpha='A'+i-1;
        while(j<=i)
        {
            cout<<alpha;
            j++;
        }
        cout<<endl;
        i++;
    }
}
//output
// A
// BB
// CCC