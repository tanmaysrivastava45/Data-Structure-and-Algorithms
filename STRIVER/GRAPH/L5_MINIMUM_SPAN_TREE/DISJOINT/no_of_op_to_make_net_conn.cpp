#include <bits/stdc++.h>
using namespace std;

class Disjoint {
    vector<int> size, parent;
public:
    Disjoint(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUparent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ul_p_u = findUparent(u);
        int ul_p_v = findUparent(v);

        if (ul_p_u == ul_p_v) return;

        if (size[ul_p_u] < size[ul_p_v]) {
            parent[ul_p_u] = ul_p_v;
            size[ul_p_v] += size[ul_p_u];
        } else {
            parent[ul_p_v] = ul_p_u;
            size[ul_p_u] += size[ul_p_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint obj(n);
        int usedConnections = 0;
        int m = connections.size();

        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            if (obj.findUparent(u) != obj.findUparent(v)) {
                usedConnections++;
                obj.UnionBySize(u, v);
            }
        }

        int extraEdges = m - usedConnections;
        int needed = n - (usedConnections + 1);

        if (needed > extraEdges) return -1;
        return needed;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}
    };

    Solution sol;
    int result = sol.makeConnected(n, connections);
    cout << "Minimum operations to connect all computers: " << result << endl;

    return 0;
}
