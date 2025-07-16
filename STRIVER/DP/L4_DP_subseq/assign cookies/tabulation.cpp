#include<bits/stdc++.h>
using namespace std;
class Solution {   
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = g.size();
    int m = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i - 1] <= s[j - 1]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

};
int main(){
    // Input: g = [1,2,3], s = [1,1]
    // Output: 1

    Solution obj;
    vector<int>g = {1,2,3};
    vector<int>s = {1,1};
    cout<<obj.findContentChildren(g,s)<<endl;

}