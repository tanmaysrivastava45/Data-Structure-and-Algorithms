#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
    int timer = 1;
private: 
    void dfs(int a,int parent,vector<int>adj[],vector<bool>&visited,int tin[],
    int low[],vector<vector<int>>&ans){
      visited[a]=1;
      tin[a]=low[a]=timer;
      timer++;
      for(auto it : adj[a]){
        if(it== parent)continue;
        if(!visited[it]){
            dfs(it,a,adj,visited,tin,low,ans);
            low[a] = min(low[it],low[a]);
            if(low[it]>tin[a]){
                ans.push_back({it,a});
            }
        }else{
            low[a] = min(low[it],low[a]);
        }
      }
     
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>visited(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>ans;
        dfs(0,-1,adj,visited,tin,low,ans);
        return ans;
    }
};

int main(){
      int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}