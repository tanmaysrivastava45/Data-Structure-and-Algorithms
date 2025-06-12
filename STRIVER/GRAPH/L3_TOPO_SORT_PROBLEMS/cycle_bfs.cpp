#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V, 0);
        vector<int> adj[V];

        // Build adjacency list and compute in-degrees
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Add all nodes with 0 in-degree to queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If topo sort includes all nodes, no cycle
        return topo.size() != V;
    }
};

// Example usage
int main() {
    Solution sol;

    // Example 1: Contains cycle
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};
    cout << "Graph 1 has cycle? " << (sol.isCyclic(V1, edges1) ? "Yes" : "No") << endl;

    // Example 2: No cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    cout << "Graph 2 has cycle? " << (sol.isCyclic(V2, edges2) ? "Yes" : "No") << endl;

    return 0;
}
