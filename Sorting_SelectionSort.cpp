#include<iostream>
using namespace std;

void sorting(int array[],int n)
{
 for(int i=0;i<n-1;i++)
 {
    int minindex=i;
    for(int j=i+1;j<n;j++)
    {
        if(array[j]<array[minindex])
        {
             minindex=j;
        }

    }
    swap(array[i],array[minindex]);
 }
}

void printarray(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[6]={18,13,45,33,10,25};
    cout<<"this is sorted array"<<endl;
    sorting(arr,6);
    printarray(arr,6);
}