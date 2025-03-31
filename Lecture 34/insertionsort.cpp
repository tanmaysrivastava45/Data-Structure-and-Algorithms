#include<iostream>
using namespace std;

void insertion(int *arr,int s,int e)
{
    if(s>e)
    {
        return ;
    }
    int curr=arr[s];
    int j=s-1;
    while(j>=0)
    {
      if(arr[j]>curr)
      {
        arr[j+1]=arr[j];
        j--;
      }
      else{
        break;
      }
    }
    arr[j+1]=curr;
    insertion(arr,s+1,e);
}

int main()
{
    int arr[]={2,1,5,45,18,7,23,9};
    int s=0;
    int e=7;
    insertion(arr,s,e);
    for(int i=0;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
}