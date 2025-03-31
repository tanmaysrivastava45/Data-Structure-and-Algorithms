#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    int i=1;
    while (i<=n)
    {
        int j=1;
        
        while(j<=n)
        {
            char alpha='A'+count;
            cout<<alpha;
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
}
// output 
// ABC
// DEF
// GHI