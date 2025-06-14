#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            // If the graph is undirected, also add this:
            // adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src}); // (distance, vertex)

        while (!pq.empty()) {
            int temp_dist = pq.top().first;
            int vertice = pq.top().second;
            pq.pop();

            for (auto it : adj[vertice]) {
                int nd = it.first;
                int dis = it.second;
                if (temp_dist + dis < dist[nd]) {
                    dist[nd] = temp_dist + dis;
                    pq.push({dist[nd], nd});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 5; // number of vertices
    int E = 6; // number of edges
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };
    int src = 0;

    Solution obj;
    vector<int> result = obj.dijkstra(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
