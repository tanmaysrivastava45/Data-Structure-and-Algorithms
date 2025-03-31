#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    char ch[]="tanmay";
    cout<<arr<<endl;
    char *ek=ch;
    cout<<ch[0]<<" "<<ek[0]<<endl;
   // important to notice that it will print whole char array unlike the one which print only the address of first element
    cout<<ch<<endl;

    char *c=&ch[0];
    // prints entire string 
    cout<<c<<endl;

    char temp='z';
    char *p=&temp;

    cout<<p<<endl;
    cout<<*p<<endl;
   /*Integer array (int arr[5]): When you do cout << arr, it prints the address of the first element of the array,
    because arr is essentially a pointer to the first element of the integer array. It doesn't print the contents of the array, but the memory address (pointer). 
    Character array (char ch[7]): When you print a character array (cout << ch), 
   cout treats it as a C-style string and prints the entire string until it encounters a null terminator ('\0'). In this case, "tanmay" is null-terminated automatically,
   so it prints the entire string.
   Character pointer (char* c): When you print c, which is a pointer to the first element of the character array, the same thing happens:
    it prints the string starting from the memory location c points to, up until the null terminator.
   Single character pointer (char *p): Here's the key part. You have: */
   char th='a';
   char *hai=&th;
   th++;
   cout<<*hai<<endl;
}