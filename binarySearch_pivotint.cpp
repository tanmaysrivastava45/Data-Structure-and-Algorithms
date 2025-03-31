#include<bits/stdc++.h>
using namespace std;

int pivotint(int arr[],int n)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
    if(arr[mid]<arr[mid+1]&& arr[mid-1]>arr[mid])
    {
        return mid;
    }
    else if(arr[mid]>arr[mid+1])
    {
        s=mid+1;
    }
    else{e=mid;}
    }
}
int main()
{
    int array[5]={7,9,1,2,3};
    cout<<pivotint(array,5);
}