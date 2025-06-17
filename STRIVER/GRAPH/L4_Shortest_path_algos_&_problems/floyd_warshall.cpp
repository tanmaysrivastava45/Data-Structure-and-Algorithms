#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // Avoid integer overflow for unreachable paths
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                    
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // inorder to check for the negative cycles
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(dist[i][j]<0){
        //             cout<<"negative cycle detected"<<endl;
        //         }
        //     }
        // }
    }
};

// Driver code
int main() {
    const int INF = 1e9; // Representation of infinity
    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    Solution sol;
    sol.floydWarshall(dist);

    int n = dist.size();
    cout << "Shortest distances matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
