#include<iostream>
using namespace std;

int getsum(int *arr,int n)
{
    int sum=0;
 for(int i=0;i<n;i++)
 {
  sum=sum+arr[i];
 }
return sum;
}

int main()
{
    int n;
    cin>>n;
    // heap memory (dynamic memory)
    int *arr=new int[n];
    for(int i=0 ;i<n;i++)
    {
        cin>>arr[i];   
    }
 cout<<"answer is : "<<getsum(arr,n);
 
 // need to delete the memory manually since it is not static
 delete []arr;
}