#include<iostream>
using namespace std;

string reverse(string & s,int i,int e)
{
  swap(s[i],s[e]);
 i++;
 e--;
 if(i>e)
 {
    return s;
 }
 
 
  return reverse(s,i,e);
 

}

int main()
{

// through simple loop and swapping 

    // string s = "abcde";
    // int n=s.length()-1;
    // int i=0;
    // while(i<n)
    // {
    //     swap(s[i],s[n]);
    //     i++;
    //     n--;
    // }
    // cout<<s<<endl;


 // Recursion
    string s="abcde";
    int i=0;
    int e=s.length()-1;
    string ans=reverse(s,i,e);
    cout<<ans<<endl;


}