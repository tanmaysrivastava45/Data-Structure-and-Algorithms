#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<*p<<endl;
}
void update(int *p)
{
  p=p+1;
   // *p=*p+1;
   cout<<p<<endl;
}
int addition(int *arr,int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
   {
    sum +=  arr[i];
   }
   return sum;
  
}

int main()
{
  // int value=5;
  // int *p=&value;
  // cout<<"before"<<endl;
  // print(p);
  // update(p);
  // cout<<"after : "<<endl;
  // // print(p);
  // cout<<"check : "<<*p<<endl;


  int arr[5]={1,2,3,4,5};
  cout<<"sum is :"<<addition(arr+2,3);
  // like we can give the starting point of array as it will only take the reference or pointer
}