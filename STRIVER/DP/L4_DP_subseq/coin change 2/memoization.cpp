#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int ind, vector<int>& coins, int target, vector<vector<int>>&dp){
        // base case
        if(ind==0){
            if(target%coins[0]==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[ind][target]!=-1)return dp[ind][target];

       int nottake = recursion(ind-1,coins,target,dp);
       int take = 0;
       if(target>=coins[ind]){
          take = recursion(ind,coins,target-coins[ind],dp);
       }

       return dp[ind][target] = take + nottake;
    }    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return recursion(n-1,coins,amount,dp);
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