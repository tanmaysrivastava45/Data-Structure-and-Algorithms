#include<iostream>
using namespace std;

bool Search (int array[],int size,int key)
{
   for(int i=0; i<size;i++)
   {
    if (array[i]==key)
    {
      return 1;
    }
   }
   return 0;
}

int main()
{
    int key;
    cin>>key;

    int elements[6]={2,5,4,6,8,7};
    bool found=Search(elements,6,key);
    
    if (found)
    {
      cout<<"key is found"<<endl;
    }
    else{cout<<"key is absent"<<endl;}

}