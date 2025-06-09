#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfss(int i, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& ans) {
        ans.push_back(i);
        visited[i] = true;
        for (int j = 0; j < adj[i].size(); j++) {
            if (!visited[adj[i][j]]) {
                dfss(adj[i][j], visited, adj, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        int n = adj.size();
        vector<bool> visited(n, false);
        dfss(0, visited, adj, ans); // start DFS from node 0
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
