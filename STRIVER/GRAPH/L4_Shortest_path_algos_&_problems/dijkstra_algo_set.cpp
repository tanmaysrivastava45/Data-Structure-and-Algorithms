#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // USING SET
        vector<pair<int,int>>adj[V];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto element = *(st.begin());
            int originDist = element.first;
            int node = element.second;
            st.erase(element);

            for(auto it : adj[node]){
                int edgewt = it.second;
                int tempnode = it.first;
                if(originDist + edgewt < dist[tempnode]){
                    if(dist[tempnode] != 1e9){
                        st.erase({dist[tempnode], tempnode});
                    }
                    dist[tempnode] = originDist + edgewt;
                    st.insert({dist[tempnode], tempnode});
                }
            }
        }

        return dist;
    }
};

// Driver code to test
int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };
    int src = 0;

    vector<int> result = sol.dijkstra(V, edges, src);
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < result.size(); ++i)
        cout << "Node " << i << ": " << result[i] << "\n";

    return 0;
}
