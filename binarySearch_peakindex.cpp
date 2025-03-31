#include<iostream>
using namespace std;
// we could have done it through linear search by compacring it with intmin but the time complexity of that would be O(n) whereas for 
  // below code it is O(logn)
    int peakIndexInMountainArray(int arr[],int n) {
        int start=0;
        int end=n-1;
        int mid= start+ (end-start)/2;
        // while(start<=end)
        // {
        //     if(arr[mid]<arr[mid+1])
        //     {
        //         start=mid+1;
        //     }
        //     else if(arr[mid-1]>arr[mid])
        //     {
        //         end=mid-1;
        //     }
        //     else{ return mid; }
        //     mid=start+(end-start)/2;
        // }
        // return mid;
          while(start<end)
        {
            if(arr[mid]<arr[mid+1])
            {
                start=mid+1;
            }
            else{
               end=mid;}
            mid=start+(end-start)/2;
        }
        return mid;
    }
    int main()
    {
        int arr[7]={1,2,45,6,4,3,2};
        cout<<peakIndexInMountainArray(arr,7);
    }
