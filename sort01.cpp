#include<iostream>
using namespace std;

void sort01(int arr[],int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(arr[i]==0 && i<j)
        {
         i++;
        }
        while(arr[j]==1 && i<j)
        {
            j--;
        }
       swap(arr[i],arr[j]);
       i++;
       j--;
    }
}

void printarray(int arr[],int n)
{
 for(int i=0;i<n;i++)
 {
    cout<<arr[i]<<" ";
 }
}

int main()
{
    int array[6]={1,0,1,1,0,0};
    sort01(array,6);
    printarray(array,6);
}