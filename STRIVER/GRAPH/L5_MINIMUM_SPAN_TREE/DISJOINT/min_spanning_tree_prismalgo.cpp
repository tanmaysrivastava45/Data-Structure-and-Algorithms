#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V, 0);
        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) continue;

            visited[node] = 1;
            sum += wt;

            for(auto it : adj[node]) {
                int adjnode = it[0];
                int edwt = it[1];
                if(!visited[adjnode]) {
                    pq.push({edwt, adjnode});
                }
            }
        }

        return sum;
    }
};

// Driver code
int main() {
    int V = 5; // number of vertices
    vector<vector<int>> adj[V];

    // Example Graph
    // Add undirected edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    Solution obj;
    cout << "Sum of weights of MST is: " << obj.spanningTree(V, adj) << endl;
    return 0;
}
