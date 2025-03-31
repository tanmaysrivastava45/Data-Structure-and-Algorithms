#include<iostream>
using namespace std;

void printarray(int arr[],int size)
{
    cout<<"printing the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
    cout<<"array printed";
}

int main()
{
    int third[5]={2,3,6,4,9};
    printarray(third,5);
    return 0;
}

// different types of array 
// #include<iostream>
// using namespace std;
// int main()
// {
//     char array[5]={'a','b','c','s','r'};
//     for(int i=0 ; i<5; i++)
//     {
//         cout<<array[i];
//     }
// }