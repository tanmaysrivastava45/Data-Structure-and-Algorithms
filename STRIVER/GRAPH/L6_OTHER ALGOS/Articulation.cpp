#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  private: 
    int timer = 0;
    void dfs(int node,int parent,vector<bool>&visited,vector<int>&mark,
    vector<int>adj[],int tin[],int low[]){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it==parent)continue;
            if(!visited[it]){
                dfs(it,node,visited,mark,adj,tin,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent !=-1){
                     mark[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent ==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>mark(V,0);
        vector<bool>visited(V,0);
        int tin[V];
        int low[V];
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,visited,mark,adj,tin,low);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4},
        {2, 4}, {2, 3}, {3, 4}
    };

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;

}