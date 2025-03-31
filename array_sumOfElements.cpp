#include<iostream>
using namespace std;

int sumOfElements(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum = sum +arr[i];
    }
    return sum;
}
int main()
{
    cout<<"enter the size of array : "<<endl;
    int size;
    cin>>size;

    int elements[100];
    for(int i=0 ; i<size ; i++)
    {
        cin>>elements[i];
    }
    cout<<"sum of elements of array is : "<< sumOfElements(elements,size);

}