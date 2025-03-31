#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string name = "TANMAY";
    stack<char>st;
    for(int i=0;i<name.length();i++){
        st.push(name[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    cout<<ans<<endl;
}