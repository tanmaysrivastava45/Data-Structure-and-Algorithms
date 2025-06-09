#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> matrix[n+1];
    for(int i=0;i<m;i++){
        int v,u;
        cin>>v>>u;
        matrix[v].push_back(u);
        // if directed then avoid next line 
        matrix[u].push_back(v);
    }
}

// if the graph is having weighted edge then make vector<pair<int,int>>matrix[n+1];
// for undirected - Space complexity = O(2xE)

// for directed - Space complexity = O(E)

