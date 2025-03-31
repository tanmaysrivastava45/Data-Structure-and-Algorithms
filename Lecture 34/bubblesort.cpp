#include<iostream>
using namespace std;

void Bubble(int *arr,int s,int e)
{

    if(e==0 || e==1)
    {
        return;
    }
   for(int i=0;i<e;i++)
   {
     if(arr[i]>arr[i+1])
     {
        swap(arr[i],arr[i+1]);
     }
   }
   Bubble(arr,s,e-1);
}

int main()
{
    int arr[]={2,17,4,62,9,23,45,18,5};
    int s=0;
    int e=8;
    Bubble(arr,s,e);
    for(int i=0;i<e;i++)
    {
       cout<<arr[i]<<" ";
    }
    
}