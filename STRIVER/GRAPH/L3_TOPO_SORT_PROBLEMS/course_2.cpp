#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> indegree(V, 0);
        vector<int> adj[V];

        // Build the adjacency list and compute in-degrees
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (order.size() == V)
            return order;  // Valid topological order
        return {};         // Cycle detected
    }
};

// 🔁 Test the function
int main() {
    Solution sol;

    // Example 1: No cycle
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Valid course order (Example 1): ";
    for (int course : result1) cout << course << " ";
    cout << endl;

    // Example 2: Cycle present
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1,0},{0,1}};
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Valid course order (Example 2): ";
    if (result2.empty()) cout << "No valid order (cycle present)";
    else for (int course : result2) cout << course << " ";
    cout << endl;

    return 0;
}
