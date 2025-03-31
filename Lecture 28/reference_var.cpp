#include<iostream>
using namespace std;

// example of pass by value
void update1 (int c)
{
    c++;
}

// example of pass by reference 
void update2(int &x)
{
    x++;
}

int main()
{
    // this is reference variable 
    /*
    int  i=45;
    int &j=i;
    cout<<"before : "<<i<<endl;
    i++;
    cout<<"after : "<<i<<endl;
    cout<<"after : j : "<<j<<endl;
    j++;
    cout<<"after : i : "<<i<<endl;
    */

   // for pass by value;
    // int i=45;
    // cout<<i<<endl;
    // update1(i);
    // cout<<i<<endl;


    // for pass by reference 
    int i=45;
    cout<<i<<endl;
    update2(i);
    cout<<i<<endl;

}