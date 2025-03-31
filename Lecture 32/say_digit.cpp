#include<iostream>
using namespace std;

void saydigit(int n)
{
    string array[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    // base case
    if(n==0)
    {
        return ;
    }
    
    // processing 
    int digit=n%10;
    n=n/10;
   

    //recursive relation 

    saydigit(n);
    cout<<array[digit]<<" ";
    
}

int main()
{
    int n;
    cin>>n;
    
    saydigit(n);
}