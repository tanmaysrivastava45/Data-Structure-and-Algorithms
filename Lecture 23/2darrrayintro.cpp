#include<iostream>
using namespace std;

bool ispresent(int arr[2][3],int target,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(arr[i][j]==target)
            {
               return 1;
            }
           
        }
    }
    return 0;
}
void printsum(int arr[2][3],int rows,int col)
{int maxi=INT32_MIN;
    for(int i=0;i<rows;i++)
    {
        
        int sum=0;
        for(int j=0;j<col;j++)
        {
         sum=sum+arr[i][j];
        }
        if(sum>maxi)
        {
            maxi=sum;
        }
        
    }
    cout<<maxi<<endl;
}
// 
int main()
{
    int arr[2][3];
    // taking input of 2d array 
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    // now printing the 2d array 
    for(int i=0;i<2;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<ispresent(arr,9,2,3);
    printsum(arr,2,3);
}