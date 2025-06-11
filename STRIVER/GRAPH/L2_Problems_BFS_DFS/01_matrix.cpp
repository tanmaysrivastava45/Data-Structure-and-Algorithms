#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> copy_mat(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<pair<pair<int, int>, int>> q;

    // Push all 0s into the queue with distance 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    int arr1[] = {-1, 0, 1, 0};
    int arr2[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        copy_mat[row][col] = steps;

        for (int i = 0; i < 4; i++) {
            int nrow = row + arr1[i];
            int ncol = col + arr2[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && mat[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, steps + 1});
                visited[nrow][ncol] = true;
            }
        }
    }

    return copy_mat;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Updated Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
