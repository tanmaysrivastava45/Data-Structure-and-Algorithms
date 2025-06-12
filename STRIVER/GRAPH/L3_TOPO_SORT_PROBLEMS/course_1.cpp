#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> indegree(V, 0);
        vector<int> adj[V];

        // Build the adjacency list and in-degree array
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return order.size() == V;
    }
};

// Example usage
int main() {
    Solution sol;

    // Test case 1: Cycle present (cannot finish all)
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}, {0, 1}};
    cout << "Can finish all courses? " 
         << (sol.canFinish(numCourses1, prerequisites1) ? "Yes" : "No") << endl;

    // Test case 2: No cycle (can finish all)
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Can finish all courses? " 
         << (sol.canFinish(numCourses2, prerequisites2) ? "Yes" : "No") << endl;

    return 0;
}
