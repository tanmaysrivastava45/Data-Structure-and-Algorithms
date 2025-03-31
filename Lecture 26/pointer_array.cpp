#include<iostream>
using namespace std;
int main()
{
    // int arr[10]={2,4,6,8};

    // playing with the pointers of array

    // cout<<"address of first memory block is : "<<arr<<endl;
    // cout<<"address of first memory block is : "<<&arr[0]<<endl;
    // cout<<"value of first ele : "<<*arr<<endl;
    // cout<<"value of second ele : "<<*(arr+1)<<endl;
    // cout<<"value increased : "<<*arr +1<<endl;
    
    //  another way of writing the indexes and array relation using the pointers
    // int i=3;
    // cout<<i[arr]<<endl;
    // cout<<*(i+arr)<<endl;

    // playing with size of array and pointers f

    // int temp[10];
    // cout<<"size of temp : "<< sizeof(temp)<<endl;
    // cout<<"1st : "<<sizeof(*temp)<<endl;
    // cout<<"2nd : "<<sizeof(&temp)<<endl;
    // int *ptr=&temp[0];
    // cout<<"3rd : "<<sizeof(ptr)<<endl;
    // cout<<"4th : "<<sizeof(*ptr)<<endl;
    // cout<<"5th : "<<sizeof(&ptr)<<endl;

    // basic things about pointers

    /*
    int a[20]={3,5,7,3,9,8};
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<&a[0]<<endl;
   
    int *p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    */

   

    // int arr[10];
    //  // Error// extreme important
    // // arr=arr+1;
    // int *i=&arr[0];
    // cout<<i<<endl;
    // i=i+1;
    // cout<<i<<endl;
    

    // impo
    // int arr[5]={11,21,31};
    // int *p=arr;
    // cout<<*p<<endl;

    // post increment and pre increment 
    int val=45;
    int sum=++val +1;
    cout<<sum<<"  "<<val<<endl;

} 