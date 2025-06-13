#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        queue<pair<int,int>> q;
        q.push({src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            int node = it.first;
            int walk = it.second;
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {
                if (dist[adj[node][i]] > walk) {
                    q.push({adj[node][i], walk + 1});
                    dist[adj[node][i]] = walk + 1;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dist[i] != INT_MAX) {
                ans.push_back(dist[i]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    // Example graph:
    // 0 -> 1, 2
    // 1 -> 2
    // 2 -> 3
    // 3 -> (no outgoing edge)
    vector<vector<int>> adj = {
        {1, 2},
        {2},
        {3},
        {}
    };

    int source = 0;

    Solution sol;
    vector<int> result = sol.shortestPath(adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
