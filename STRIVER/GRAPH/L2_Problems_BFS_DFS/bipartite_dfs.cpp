#include <iostream>
#include <vector>
using namespace std;

class Solution {
private: 
    bool dfs(int start, vector<int>& color, vector<vector<int>>& graph, int c) {
        color[start] = c;
        for (int i = 0; i < graph[start].size(); i++) {
            int neighbor = graph[start][i];
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, color, graph, 1 - c)) {
                    return false;
                }
            } else if (color[neighbor] == color[start]) {
                return false;
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
                if (!dfs(i, color, graph, 0)) {
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

    // Example 1: Bipartite
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
