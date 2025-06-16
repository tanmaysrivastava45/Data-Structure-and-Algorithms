#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create the adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Initialize distance array
        vector<int> dist(n + 1, 1e7);
        dist[k] = 0;

        // Step 3: Min-heap priority queue for Dijkstra's
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        // Step 4: Dijkstra's Algorithm
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int currDist = top.first;
            int node = top.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (currDist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = currDist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Step 5: Find the maximum time from source to any node
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e7) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;

    int result = sol.networkDelayTime(times, n, k);
    cout << "Network delay time: " << result << endl;

    return 0;
}
