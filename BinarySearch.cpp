#include<iostream>
using namespace std;

int binarysearch(int array[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(array[mid]==key)
        {
            return mid;
        }
        if(key>array[mid])
        {
            start=mid+1;
        }
        else{end=mid-1;}
        
        mid=start+(end-start)/2;
    }
    return -1;
}

int main()
{
    int array1[6]={2,4,7,8,18,45};
    int array2[5]={1,4,5,7,9};
    
    int index1= binarysearch(array1,6,18);
    int index2 = binarysearch(array2,5,40);
    cout<<index1;
    cout<<index2;

}