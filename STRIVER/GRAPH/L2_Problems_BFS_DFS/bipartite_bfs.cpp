#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private: 
    bool bfs(int start, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            for (int i = 0; i < graph[ele].size(); i++) {
                int neighbor = graph[ele][i];

                if (color[neighbor] == -1) {
                    // Assign opposite color
                    color[neighbor] = 1 - color[ele];
                    q.push(neighbor);
                } else {
                    // Same color on both ends ⇒ Not bipartite
                    if (color[neighbor] == color[ele]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, color, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// 🔍 Sample usage
int main() {
    Solution sol;

    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Example 2: Not bipartite
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    cout << "Graph 1 is bipartite: " << (sol.isBipartite(graph1) ? "Yes" : "No") << endl;
    cout << "Graph 2 is bipartite: " << (sol.isBipartite(graph2) ? "Yes" : "No") << endl;

    return 0;
}
