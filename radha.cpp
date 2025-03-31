#include<iostream> 
using namespace std;

void sort012(int arr[], int n)
{
   //   Write your code here
  int i=0;
  int j=n-1;
  while(i<j)
  {
     while(arr[i]==0 && i<j)
     {
        i++;
     }
     while(arr[j]==2 && i<j)
     {
        j--;
     }
   }

if(arr[i]!=arr[j] && arr[i]<arr[j] && i<j)
     {
        swap(arr[i],arr[j]);
        i++;
        j--;
     }
  }

void printarray(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int array[7]={0,1,2,1,2,1,2};
    sort012(array,7);
     printarray(array,7);
}