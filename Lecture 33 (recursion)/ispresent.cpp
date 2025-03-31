#include<iostream>
using namespace std;

int print(int arr[],int size)
{
    cout<<"Size of the array is : "<< size<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearsearch(int arr[],int size, int key)
{
    print(arr,size);
    if(size==0)
    {
        return false;
    }
    if(arr[0]==key)
    {
        return true;
    }
    else{
        return linearsearch(arr+1,size-1,key);
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int size=7;
    int key=7;
    bool ans=linearsearch(arr,size,key);
    if(ans)
    {
        cout<<"PRESENT"<<endl;
    }else{
        cout<<"NOT PRESENT"<<endl;
    }
}