#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid,
             vector<pair<int, int>>& vec, int basei, int basej) {
        visited[row][col] = true;
        vec.push_back({row - basei, col - basej});

        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + arr1[i];
            int ncol = col + arr2[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, visited, grid, vec, basei, basej);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> uniqueShapes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, visited, grid, shape, i, j);
                    uniqueShapes.insert(shape);
                }
            }
        }

        return uniqueShapes.size();
    }
};

// Sample test case
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 0}
    };

    int result = sol.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << result << endl;

    return 0;
}
