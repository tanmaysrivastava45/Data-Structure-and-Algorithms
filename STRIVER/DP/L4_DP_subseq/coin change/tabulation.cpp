#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
            else
            dp[0][i]=1e9;

        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake = dp[i-1][j];
                int take = 1e9;
                if(j>=coins[i]){
                   take = 1 + dp[i][j-coins[i]];
                }

              dp[i][j] = min(take,nottake);
            }
        }
        int ans = dp[n-1][amount];
        return (ans>=1e9)? -1 : ans;
    }
};



int main() {
    vector<int> arr = {1, 2, 3};
    int T = 7;
    
    // Call the function to find the minimum number of elements needed
    Solution obj;
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << obj.coinChange(arr,T) << endl;
    
    return 0; // Return 0 to indicate successful program execution
}