#include<iostream>
using namespace std;

int main()
{
    int val=45;
    int *ptr=&val;
    int **pr=&ptr;
  
// printing the value declared initially

    cout<<"value :"<<val<<endl;
    cout<<"value :"<<*ptr<<endl;
    cout<<"value :"<<**pr<<endl;

// printing the value in the box ptr;

    cout<<"address of val : "<<&val<<endl;
    cout<<"address of val : "<<ptr<<endl;
    cout<<"address of val : "<<*pr<<endl;

// printing the value in the box pr or the add of ptr

    cout<<"address of ptr : "<<&ptr<<endl;
    cout<<"address of ptr : "<<pr<<endl;

// printing the address of the box pr 
 
    cout<<"address of the box pr : "<<&pr<<endl;

}