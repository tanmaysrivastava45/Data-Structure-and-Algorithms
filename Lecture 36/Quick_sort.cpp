#include<iostream>
using namespace std;

int findPivot(int *arr,int s,int e)
{
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot) ////////
        {
            count++;
        }
    }
    int pivotidx=s+count;
    swap(arr[s],arr[pivotidx]);

    ////////////////////////
    while(s<pivotidx&& e>pivotidx)
    {
        while( arr[s]<=arr[pivotidx])
        {
            s++;
        }
         while( arr[e]>arr[pivotidx])
        {
            e--;
        }
      if(s<pivotidx&& e>pivotidx)//// here s<pivotidx&& e>pivotidx this is correct  
      // and i wrote arr[s]>arr[pivotidx] && arr[e]<arr[pivotidx]
      {
        swap(arr[s++],arr[e--]);
      }
    }
    ///////////////////////////
    return pivotidx;
}

void Quicksort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int pivotidx = findPivot(arr,s,e);
    Quicksort(arr,s,pivotidx-1);
    Quicksort(arr,pivotidx+1,e);
}

int main()
{
    int arr[]={2,1,3,45,18,9,1,4};
    int n=8;
    Quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}