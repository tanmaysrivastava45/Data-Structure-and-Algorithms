//<--------------to initialize entire array using a given particular value---------------------->

#include<iostream>
using namespace std;
int main()
{
    int array[100];
    fill_n(array,100,1);
    for(int i=0;i<100;i++)
    {
        cout<<array[i];
    }

}