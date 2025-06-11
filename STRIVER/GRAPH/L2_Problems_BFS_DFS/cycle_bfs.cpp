#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool bfs(int k, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int,int>> q;
        q.push({k, -1});
        visited[k] = true;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if(neighbor != parent) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                if(bfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Driver code
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1} // this creates a cycle
    };

    Solution sol;
    if(sol.isCycle(V, edges)) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}
