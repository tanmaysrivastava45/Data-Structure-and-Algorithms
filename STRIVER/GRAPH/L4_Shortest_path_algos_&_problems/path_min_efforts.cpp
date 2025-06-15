#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto t = pq.top();
            int diff = t.first;
            int row = t.second.first;
            int col = t.second.second;
            pq.pop();
            
            if (row == n - 1 && col == m - 1) return diff;
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int neweffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                    if (neweffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = neweffort;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

// Sample driver code
int main() {
    Solution sol;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int result = sol.minimumEffortPath(heights);
    cout << "Minimum Effort Required: " << result << endl;

    return 0;
}
