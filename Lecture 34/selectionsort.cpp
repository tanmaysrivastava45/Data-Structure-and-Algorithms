#include<iostream>
using namespace std;

void selection(int *arr,int s,int e)
{
  // base case 
  if(s==e+1)
  {
    return;
  }
  int mini=s;
  // writing i=s+1 so that the elements from index to n get clear
  for(int i=s+1;i<=e;i++)
  {
    if(arr[mini]>arr[i])
    {
        mini=i;
    }
  }
  swap(arr[s],arr[mini]);
  selection(arr,s+1,e);
}
int main()
{
    int arr[]={2,1,4,34,45,13,26,49,18};
    int s=0;
    int e=8;
    selection(arr,s,e);
    for(int i=0;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
}