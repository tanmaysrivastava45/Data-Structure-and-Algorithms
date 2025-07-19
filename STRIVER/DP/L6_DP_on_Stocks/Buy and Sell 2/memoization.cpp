
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int buy, vector<int>& prices, int n, int profit,
    vector<vector<int>>&dp){
        if(ind == n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy ==1){
          profit = max(-prices[ind]+f(ind+1,0,prices,n,profit,dp),f(ind+1,1,prices,n,
          profit,dp));
        }else{
            profit = max(prices[ind]+f(ind+1,1,prices,n,profit,dp),f(ind+1,0,prices,n,
            profit,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,profit,dp);
    }
};

int main() {
    int n = 6;
    vector<int>Arr = {7, 1, 5, 3, 6, 4};
    Solution obj;
    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << obj.maxProfit(Arr);

    return 0;
}
