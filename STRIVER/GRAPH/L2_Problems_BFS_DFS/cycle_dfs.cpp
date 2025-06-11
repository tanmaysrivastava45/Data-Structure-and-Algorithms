#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfs(int k, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[k] = true;

        for(int i = 0; i < adj[k].size(); i++) {
            int neighbor = adj[k][i];
            if(!visited[neighbor]) {
                if(dfs(neighbor, adj, visited, k)) {
                    return true;
                }
            } else if(neighbor != parent) {
                // A visited neighbor that isn't the parent means a cycle
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        // Build adjacency list
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(V, false);

        // DFS for each disconnected component
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, -1)) {
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
        {4, 1} // introduces a cycle
    };

    Solution sol;
    if(sol.isCycle(V, edges)) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}
