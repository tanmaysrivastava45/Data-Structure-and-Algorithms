#include <iostream>
using namespace std;

void reverse(int array[], int n)
{
     int start = 0;
     int end = n - 1;

    while(start<=end)
    {
        swap(array[start],array[end]);//start and end must be looked as the indices of the array and not to mistaken as an element
        start++;
        end--;
    }
}

void print(int array[], int n)
{
    for (int i=0; i < n; i++)
    {
        cout << array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr1[6] = {4, 5, 8, 2, 7, 3};
    int arr2[5] = {1, -8, 5, 7, 6};

    reverse(arr1, 6);
    reverse(arr2, 5);

    print(arr1, 6);
    print(arr2, 5);
}