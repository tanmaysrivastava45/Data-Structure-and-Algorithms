#include<iostream>
using namespace std;

void update(int **ptr)
{
    *ptr=*ptr+1;
}

int main()
{
    int val=45;
    int *ptr=&val;
    int **pr=&ptr;
  
// printing the values in the particular boxes
cout<<"box 1 : "<<val<<endl;
cout<<"box 2 : "<<ptr<<endl;
cout<<"box 3 : "<<pr<<endl;

update(pr);

cout<<"box 1 : "<<val<<endl;
cout<<"box 2 : "<<ptr<<endl;
cout<<"box 3 : "<<pr<<endl;

}