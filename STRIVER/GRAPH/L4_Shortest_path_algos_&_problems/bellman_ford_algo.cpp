#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

// Driver Code
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int src = 0;

    Solution sol;
    vector<int> result = sol.bellmanFord(V, edges, src);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To vertex " << i << " -> " << result[i] << endl;
        }
    }

    return 0;
}
