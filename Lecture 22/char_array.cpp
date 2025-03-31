#include<iostream>
using namespace std;

bool ispalindrome(char arr[],int n)
{
    int s=0;
    int e=n-1;
    if(arr[s]!=arr[e])
    return 0;
    else{
        s++;e--;
    }
    return 1;
}

void reverse(char arr[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

int getlength(char arr[])
{
    int count=0;
    for(int i=0;arr[i]!='\0';i++)
    {
        count ++;
    }
    return count ;
}

int main()

{
    char arr[15];
   
    cout<<"enter your name"<<endl;
    cin>>arr;
   // arr[2]='\0';
    cout<<"your name is:"<<arr<<endl;
    int n=getlength(arr);
    cout <<"Length of your name is : "<< getlength(arr)<<endl;
     reverse(arr,n);
    cout<<"your reverse name is :"<<arr;
   cout<<"is palindrome : "<< ispalindrome(arr,n);



}
/// to check palindrome sample code when we need to ignore special characters and to include 
// integers
/*
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int b = 0;
    int e = s.size() - 1;

    while (b < e)
    {
        // Skip non-alphanumeric characters
        while (b < e && !isalnum(s[b])) {
            b++;
        }
        while (b < e && !isalnum(s[e])) {
            e--;
        }

        // Compare characters ignoring case
        if (tolower(s[b]) != tolower(s[e])) {
            return false;
        }

        b++;
        e--;
    }
    return true;
}

int main() {
    string s = "c1 O$d@eeD o1c";
    if (checkPalindrome(s))
        cout << "Yes, it's a palindrome" << endl;
    else
        cout << "No, it's not a palindrome" << endl;

    return 0;
}

*/