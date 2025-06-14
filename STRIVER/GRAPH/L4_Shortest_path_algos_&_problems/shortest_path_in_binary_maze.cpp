#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        pq.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        while(!pq.empty()){
            auto traverse = pq.top();
            int dis = traverse.first;
            int row = traverse.second.first;
            int col = traverse.second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                       grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        pq.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};

// Sample main() for testing
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0}
    };

    int result = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest path length: " << result << endl;

    return 0;
}
