#include<bits/stdc++.h>
using namespace std;


class Solution {
private: 
    void dfs(int i,vector<bool>&visited,vector<int>adj[]){
        visited[i]=true;
        for(int j = 0;j<adj[i].size();j++){
            if(!visited[adj[i][j]])
            dfs(adj[i][j],visited,adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};

int main(){
   vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
   Solution obj;
   cout<<obj.findCircleNum(isConnected);
}