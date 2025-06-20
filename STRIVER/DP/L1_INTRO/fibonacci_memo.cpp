#include<bits/stdc++.h>
using namespace std;
class Solution
{
private:
    /* data */
public:
    int func(int n,vector<int>&dp){
        if(n<=1)return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
};


int main(){
    int n = 7;
    vector<int>dp(n+1,-1);
    Solution obj;
    cout<<obj.func(n,dp)<<endl;
}