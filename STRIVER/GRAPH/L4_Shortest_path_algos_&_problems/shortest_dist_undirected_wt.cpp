#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        while(!pq.empty()){
            auto t = pq.top();
            int dis = t.first;
            int node = t.second;
            pq.pop();
            //if(dist[node] < dis) continue;

            for(auto it: adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                if(wt + dis < dist[adjnode]){
                    dist[adjnode]= wt + dis;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int>path;
        int node = n;
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };
    
    vector<int> result = sol.shortestPath(n, m, edges);
    for(int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
