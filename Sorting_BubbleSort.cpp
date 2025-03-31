#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(isSwap==false)
        {
            break;
        }
    }
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main ()
{
    int arr[6]={12,45,18,16,33,10};
    bubble_sort(arr,6);
    printarray(arr,6);
}