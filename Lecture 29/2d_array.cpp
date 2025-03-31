#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;

    // creating a 2d array using heap memory or dynamic memory
    int **arr=new int *[row];
    for(int i=0;i<row;i++)
    {
        arr[i]= new int [col];
    }

    // taking input of the 2d_array 
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    // taking the output of the 2d_array
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < row; i++)
    {
       delete[] arr[i];  // Delete each row
    }
      delete[] arr;  // Delete the array of row pointers

}