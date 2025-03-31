#include<iostream>
using namespace std;

//there are three methods to solve this problem

//Method 1

// void Reverse_Alternate(int array[],int n)
// {
//   int start=0;
//   int end=1;
//   while(end<n)
//   {
//     swap(array[start],array[end]);
//     start=start+2;
//     end=end+2;
//   }
// }

//Method 2

// void Reverse_Alternate(int array[], int size)
// {
//     for(int i=0;i<size;i+=2)
//     {
//         if(i+1<size)
//         {
//         swap(array[i],array[i+1]);
//         }
//     }
// }

//method 3
void Reverse_Alternate(int array[],int size)
{
    for(int i=0; i< size; i+=2)
    {
        if (i+1<size)
        {
            int temp=array[i+1];
            array[i+1]=array[i];
            array[i]=temp;
        }
    }
}


void print(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i];
    }
}


int main()
{
    int array[6]={2,5,6,4,1,9};
    int array2[5]={1,8,7,3,4};

    Reverse_Alternate(array,6);
    print(array,6);

    cout<<endl;

    Reverse_Alternate(array2,5);
    print(array2,5);
}