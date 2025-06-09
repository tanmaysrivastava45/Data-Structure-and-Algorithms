#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // BFS starting from node 'i'
    vector<int> bfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
        vector<int> ans;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }

    // Main function to get connected components
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(V); // adjacency list

        // Building the adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false); // visited array

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component = bfs(i, adj, visited);
                ans.push_back(component);
            }
        }

        return ans;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 4}
        // Node 5 is isolated
    };

    Solution sol;
    vector<vector<int>> components = sol.getComponents(V, edges);

    cout << "Connected Components:\n";
    for (auto& comp : components) {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
