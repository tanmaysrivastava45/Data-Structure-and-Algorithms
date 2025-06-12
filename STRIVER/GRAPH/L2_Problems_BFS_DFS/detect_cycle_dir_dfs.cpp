#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int start, vector<int> adj[], vector<bool>& visited, vector<bool>& pathVisited) {
        visited[start] = true;
        pathVisited[start] = true;

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, pathVisited)) return true;
            } else if (pathVisited[neighbor]) {
                return true;  // Cycle detected
            }
        }

        pathVisited[start] = false; // Backtrack
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]); // Directed edge
        }

        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) return true;
            }
        }
        return false;
    }
};

// 🔍 Sample usage
int main() {
    Solution sol;

    // Example 1: Contains a cycle
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 0}
    };
    cout << "Graph 1 has cycle: " << (sol.isCyclic(3, edges1) ? "Yes" : "No") << endl;

    // Example 2: No cycle
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}
    };
    cout << "Graph 2 has cycle: " << (sol.isCyclic(4, edges2) ? "Yes" : "No") << endl;

    return 0;
}
