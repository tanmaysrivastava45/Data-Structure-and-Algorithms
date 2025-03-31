#include<iostream>
using namespace std;
int main()
{
    double num=555;
    cout<<num<<endl;
    cout<<&num<<endl;
    double *ptr=&num;
    cout<<"size of ptr :"<<sizeof(ptr)<<endl;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
   
    cout<<"size of num : "<<sizeof(num)<<endl;
    

}