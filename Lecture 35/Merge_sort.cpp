#include<iostream>
using namespace std;

void Merge(int *arr,int size,int s,int e)
{
    int* ans = new int[e - s + 1];//------------------- // Declares a dynamic array of size n
    int mid=s+(e-s)/2;
    int i=s;//////////////////////////////////////
    int j=mid+1;
    int idx=0;
    while(i<mid+1 && j<e+1)
    {
        if(arr[i]<=arr[j])
        {
            ans[idx]=arr[i];
            idx++;
            i++;
        }
        else{
            ans[idx]=arr[j];
            idx++;
            j++;
        }
    }
    while(i<mid+1)
    {
        ans[idx]=arr[i];
            idx++;
            i++;
    }
     while(j<e+1)
    {
        ans[idx]=arr[j];
            idx++;
            j++;
    }
    for(int k=0;k<e-s+1;k++)//////////////////////////
    {
        arr[s+k]=ans[k];/////////////////////
    }
    delete[] ans;

}

void sort(int *arr,int size,int s,int e)
{
    int mid=s+(e-s)/2;
    if(s>=e)//////////////////////////
    {
        return ;
    }
    // left side sorting 
    sort(arr,size,s,mid);

    // right side sorting
    sort(arr,size,mid+1,e);

    // merge sorted array 
    Merge(arr,size,s,e);
}



int main()
{
    int arr[]={2,1,34,23,45,18,9,10,5};
    int size=9;
    int s=0;
    int e=8;
    sort(arr,size,s,e);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//////////////explanation /////////////////////
/*
                                       sort(0, 8)
                                /                      \
                     sort(0, 4)                          sort(5, 8)
                   /         \                     /                  \
           sort(0, 2)      sort(3, 4)          sort(5, 6)             sort(7, 8)
           /     \        /       \            /           \           /       \
     sort(0,1) sort(2,2) sort(3,3) sort(4,4) sort(5,5) sort(6,6) sort(7,7) sort(8,8)
      /    \
sort(0,0) sort(1,1)

Merging Details at Each Level
Level 4 (Base Case): Single-element arrays.

{2}, {1}, {34}, {23}, {45}, {18}, {9}, {10}, {5}
Level 3: Merging pairs of elements:

{2} + {1} → {1, 2}
{23} + {45} → {23, 45}
{18} + {9} → {9, 18}
{10} + {5} → {5, 10}
Level 2: Merging sorted subarrays:

{1, 2} + {34} → {1, 2, 34}
{23, 45} remains as is.
{9, 18} + {5, 10} → {5, 9, 10, 18}
Level 1: Merging the two halves:

{1, 2, 34} + {23, 45} → {1, 2, 23, 34, 45}
{5, 9, 10, 18} remains as is.
Final Level: Merge the two sorted halves:

{1, 2, 23, 34, 45} + {5, 9, 10, 18} → {1, 2, 5, 9, 10, 18, 23, 34, 45}







*/