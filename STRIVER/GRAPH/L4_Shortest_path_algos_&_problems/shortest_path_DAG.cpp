#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void toposort(int start, vector<bool>& visited,
                  vector<pair<int, int>> adj[], stack<int>& st) {
        visited[start] = true;
        for (auto it : adj[start]) {
            int ele = it.first;
            if (!visited[ele]) {
                toposort(ele, visited, adj, st);
            }
        }
        st.push(start);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges, int src) {
        // Step 1: Build the adjacency list
        vector<pair<int, int>> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Perform topological sort
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                toposort(i, visited, adj, st);
            }
        }

        // Step 3: Initialize distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int ele = st.top();
            st.pop();
            if (dist[ele] != 1e9) {
                for (auto it : adj[ele]) {
                    int u = it.first;
                    int wt = it.second;
                    if (dist[ele] + wt < dist[u]) {
                        dist[u] = dist[ele] + wt;
                    }
                }
            }
        }

        // Step 5: Mark unreachable nodes as -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main() {
    int V = 7;
    int E = 12;
    int src = 6;
    
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1},
        {1, 3, 1}, {1, 3, 1},
        {2, 3, 3}, {2, 3, 3},
        {4, 0, 3}, {4, 3, 2},
        {5, 4, 1}, {5, 3, 3},
        {6, 4, 2}, {6, 2, 3}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(V, E, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << ans[i] << "\n";
    }

    return 0;
}
