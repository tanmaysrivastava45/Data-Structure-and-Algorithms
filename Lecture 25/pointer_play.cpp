#include<iostream>
using namespace std;
int main()
{
    // int a=45;
    // int *p=0;
    // int *q=&a;
    // p=&a;
    // cout<<a<<endl;
    // cout<<*q<<endl;
    // cout<<q<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;

    // passed by value
    // int num=45;
    // int ans=num;
    // ++ans;
    // cout<<num<<endl;
    // cout<<ans<<endl;

    // passed by ref
    // int num=45;
    // int *ans=0;
    // ans=&num;
    // cout<<num<<endl;
    // (*ans)++;
    // cout<<num<<endl;

    // copying a pointer 

    int a=45;
    int *pt=&a;
    int *b=pt;
    cout<<pt<<"-"<<b<<endl;
    cout<<*pt<<"-"<<*b<<endl;
    cout<<pt<<endl;
    pt=pt+1;
    cout<<pt<<endl;
    
}