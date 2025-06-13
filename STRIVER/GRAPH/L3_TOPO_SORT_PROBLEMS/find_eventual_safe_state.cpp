#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> reverse[n];
        vector<int> indegree(n, 0);

        // Build reverse graph and indegree array
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                reverse[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        // Start with nodes that have 0 indegree in reverse graph (i.e. terminal nodes)
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neighbor : reverse[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(ans.begin(), ans.end()); // Sorted as required by the problem
        return ans;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 points to 1 and 2
        {2, 3},    // Node 1 points to 2 and 3
        {5},       // Node 2 points to 5
        {0},       // Node 3 points to 0
        {5},       // Node 4 points to 5
        {},        // Node 5 is terminal
        {}         // Node 6 is terminal
    };

    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    cout << "Safe Nodes: ";
    for(int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
