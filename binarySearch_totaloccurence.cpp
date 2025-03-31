#include<iostream>
using namespace std;

int firstoccur(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            end=mid-1;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
}
int lastoccur(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int middle=start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        if(arr[middle]==key)
        {
            ans=middle;
            start=middle+1;
        }
        else if(key>arr[middle])
        {
            start=middle+1;
        }
        else{
            end=middle-1;
        }
        middle=start+(end-start)/2;

    }
}
int main()
{
    
    int array[7]={1,2,3,3,3,3,5};
    int a=firstoccur(array,7,3);
    int b=lastoccur(array,7,3);
    cout<<b-a;
}
