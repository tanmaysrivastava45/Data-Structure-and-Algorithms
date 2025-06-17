#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        vector<int> dist(mod, INT_MAX);
        queue<pair<int, int>> q;

        q.push({start, 0});
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (node == end) return steps;

            for (int i = 0; i < arr.size(); ++i) {
                int newnode = (node * arr[i]) % mod;
                if (steps + 1 < dist[newnode]) {
                    dist[newnode] = steps + 1;
                    if (newnode == end) return steps + 1;
                    q.push({newnode, steps + 1});
                }
            }
        }
        return -1;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    int result = sol.minimumMultiplications(arr, start, end);
    cout << "Minimum Multiplications: " << result << endl;

    return 0;
}
