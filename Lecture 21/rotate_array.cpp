#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& arr,int k)
{
    int n=arr.size();
    vector<int>temp(n);
    for(int i=0;i<n;i++)
    {
        temp[(i+k)%n]=arr[i];
    }
   for(int i=0;i<n;i++) 
      {
        arr[i] = temp[i];
      }
}
void print(const vector<int>& arr)  /// this pass by reference is very important to keep things updated else the print function will 
// simply print the array mentioned in  main funciton .
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int>array={1,2,3,4,5,6,7};
    rotate1(array,3);
    print(array);

}
