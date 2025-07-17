#include<bits/stdc++.h>
using namespace std;

class Solution {
int MOD = 1e9+7;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,0));
        for(int i=0;i<=amount;i++){
             if(i%coins[0]==0){
                dp[0][i]=1;
             }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                    long long nottake = dp[i-1][j];
                    long long take = 0;
                    if(j>=coins[i]){
                        take = dp[i][j-coins[i]];
                    }
                    if(take+nottake>INT_MAX){
                        dp[i][j] = (take + nottake)%MOD;
                    }else
                    dp[i][j] = 1LL*(take + nottake);
            }
        }
        return dp[n-1][amount];
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    Solution obj;

    cout << "The total number of ways is " << obj.change(target,arr) << endl;

    return 0; // Return 0 to indicate successful program execution
}