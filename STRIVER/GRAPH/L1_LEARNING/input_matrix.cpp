#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int matrix[n+1][m+1];
    for(int i=0;i<m;i++){
        int v,u;
        cin>>v>>u;
        matrix[v][u]=1;
        matrix[u][v]=1;
    }
}
//  space complexity = O(n*n)