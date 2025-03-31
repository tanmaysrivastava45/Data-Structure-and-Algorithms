#include <iostream>
using namespace std;

int max(int array[], int size)
{
    int maxi=INT32_MIN;
    for (int i = 0; i < size; i++)
    {

        maxi=max(array[i],maxi);
    //    if (array[i]>mini)
    //    {
    //       mini=array[i];
    //    }

    }
    return maxi;
}

int min(int array1[],int n)
{
    int mini=INT32_MAX;
    for(int i=0 ;i<n;i++)
    {
    mini=min(array1[i],mini);
    }
    return mini;
}

int main()
{
    int n;
    cout<<"enter the size of array "<< endl;
    cin>>n;
    
    int array2[100] ;
    cout<<"enter the elements of the array "<<endl;
    for(int i=0;i<n;i++)
     {
        cin>>array2[i];
     }

    cout<<"maximum no among this is : "<<max(array2, 5)<<endl;
    cout<<"minimum no among this is : "<<min(array2,5);
}
