#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    vector<int>arr(n);
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=5;
    //arr[5]=6;
    arr.push_back(45);
    for(int i=0;i<n+2;i++)
    {
        cout<<arr[i]<<endl;
    }
}