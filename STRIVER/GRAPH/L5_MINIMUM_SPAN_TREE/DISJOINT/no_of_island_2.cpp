#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Class
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// Function to simulate number of islands
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet obj(n * m);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> ans;
    int count = 0;

    for (auto it : operators) {
        int row = it[0];
        int col = it[1];

        if (visited[row][col]) {
            ans.push_back(count);
            continue;
        }

        visited[row][col] = true;
        count++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol]) {
                // important thing to notice 
                //
                int node = row * m + col;
                int adjNode = nrow * m + ncol;

                if (obj.findUPar(node) != obj.findUPar(adjNode)) {
                    count--;
                    obj.unionByRank(node, adjNode);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

// Driver code
int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4},
        {1, 0}
    };

    vector<int> result = numOfIslands(n, m, operators);
    cout << "Island count after each operation:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Output:
Island count after each operation:
1 1 2 2 3

Explanation:
- (1,1) → new island → count = 1
- (0,1) connects to (1,1) → no new island → count = 1
- (3,3) → new island → count = 2
- (3,4) connects to (3,3) → merged → count = 2
- (1,0) → new island → count = 3
*/
