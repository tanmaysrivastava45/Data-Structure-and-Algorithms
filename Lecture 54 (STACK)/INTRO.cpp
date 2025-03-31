#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>s;
    s.push(5);
    cout<<s.top()<<endl;
    s.push(45);
    s.push(18);
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
   // cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    
}