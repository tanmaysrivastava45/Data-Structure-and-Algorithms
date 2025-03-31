#include<bits/stdc++.h>
using namespace std;

bool isSort(int *array,int size)
{
   if(size==1 || size==0)
   {
    return true;
   }
   if(array[0]>array[1])
   {
    return false;
   }
   else{
    return isSort(array+1,size-1);
   }
}
int main()
{
    int array[]={2,4,8,35,45,60};
    int size=6;
    bool ans=isSort(array,size);
    if(ans)
    {
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
}