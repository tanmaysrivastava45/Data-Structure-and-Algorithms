#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
     for(int i=1;i<n;i++)
     {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{break;}
        }
        arr[j+1]=temp;
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
    int arr[6]={2,0,2,1,1,0};
    insertionSort(arr,6);
    printarray(arr,6);

}