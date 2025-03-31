#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(10);
    q.push(45);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
}
