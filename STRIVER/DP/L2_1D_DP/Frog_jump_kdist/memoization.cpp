#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
int memoization(vector<int>&height,int n,int k,vector<int>&dp){
if(n==0)return dp[0]=0;
if(dp[n]!=-1)return dp[n];
int mini = INT_MAX;
for(int i=1;i<=k;i++){
    if(n-i>=0){
    int left = memoization(height,n-i,k,dp)+abs(height[n-i]-height[n]);
    mini = min(mini,left);
    }
}
return dp[n]=mini;
}
public:
int min_cost(vector<int>&height,int k){
    int n = height.size();
    vector<int>dp(n,-1);
    return memoization(height,n-1,k,dp);
}
};

int main(){
 vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    Solution obj;
    cout << obj.min_cost( height,k) << endl; // Print the result of the solve function
    return 0;
}