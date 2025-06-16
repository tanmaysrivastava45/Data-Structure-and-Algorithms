#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];  // adjacency list
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;  // {stops, {node, cost}}
        vector<int> dist(n, INT_MAX);  // distance array to track min cost

        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;

            if (stops > k) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (cost + edgeWt < dist[adjNode]) {
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// Driver code
int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 3, k = 1;
    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price: " << result << endl;
    return 0;
}
