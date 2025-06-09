#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfs(int V, vector<vector<int>> adj) {
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;

        visited[0] = true; // Start from node 0
        q.push(0);

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
};

int main() {
    int V = 5; // number of vertices
    vector<vector<int>> adj(V);

    // Sample undirected graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1, 4};
    adj[4] = {3};

    Solution sol;
    vector<int> result = sol.bfs(V, adj);

    cout << "BFS Traversal starting from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
