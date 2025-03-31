#include<bits/stdc++.h>
using namespace std;

vector<int> reversed(vector<int> v)
{
    int s=0;int e=v.size()-1;
    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;

    }
     return v;
}

void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}



int main()
{
    vector<int> v;
    v.push_back(11);
    v.push_back(23);
    v.push_back(45);
    v.push_back(6);
    v.push_back(12);
    v.push_back(13);

    vector<int> ans= reversed(v);
    print(ans);


}