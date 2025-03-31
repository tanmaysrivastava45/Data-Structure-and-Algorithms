#include<iostream>
using namespace std;

bool check(string & str,int i,int j)
{
    if(i>j)
    {
        return 1;
    }
    if(str[i]==str[j])
    {
        i++;j--;
        return check(str,i,j);
    }
    if(str[i]!=str[j])
    {
        return 0;
    }
}
int main()
{
    string str ="nama";
    bool ans=check(str,0,str.length()-1);
    if(ans)
    {
        cout<<"YES IT IS A PALINDROME"<<endl;
    }else{
        cout<<"NO IT IS NOT A PALINDROME"<<endl;
    }
}

