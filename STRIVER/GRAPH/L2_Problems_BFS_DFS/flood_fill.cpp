#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int val = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = color;

        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] != color && image[nrow][ncol] == val) {
                    visited[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] != color) {
                    visited[i][j] = image[i][j];
                }
            }
        }

        return visited;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    // Output the result
    cout << "Resultant image after flood fill:\n";
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
