#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int min_cost(vector<int>&height,int k){
    int n = height.size();
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){
           if(i-j>=0){
            int val = dp[i-j]+abs(height[i]-height[i-j]);
            mini = min(mini,val);
           }
        }
        dp[i]=mini;
    }
    return dp[n-1];
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