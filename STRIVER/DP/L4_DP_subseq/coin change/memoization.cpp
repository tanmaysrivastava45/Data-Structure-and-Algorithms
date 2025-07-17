#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int ind, vector<int>& coins, int target, vector<vector<int>>&dp){
        // base case
        if(ind==0){
            if(target%coins[0]==0){
                return target/coins[0];
            }else{
                return 1e9;
            }
        }
       if(dp[ind][target]!=-1)return dp[ind][target];
       int nottake = recursion(ind-1,coins,target,dp);
       int take = 1e9;
       if(target>=coins[ind]){
          take = 1 + recursion(ind,coins,target-coins[ind],dp);
       }

       return dp[ind][target] = min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = recursion(n-1,coins,amount,dp);
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