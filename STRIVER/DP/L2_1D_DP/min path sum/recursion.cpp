
#include <bits/stdc++.h>
using namespace std;

// Helper function to find the minimum sum path from (i, j) to (0, 0) in the matrix
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix) {
    if (i == 0 && j == 0) return matrix[0][0];
    if (i < 0 || j < 0) return INT_MAX;

    int up = minSumPathUtil(i - 1, j, matrix);
    int left = minSumPathUtil(i, j - 1, matrix);

    int min_prev = min(up, left);
    if (min_prev == INT_MAX) return INT_MAX; // Prevent overflow

    return matrix[i][j] + min_prev;
}


// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    return minSumPathUtil(n - 1, m - 1, matrix); // Start from the bottom-right corner
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}

