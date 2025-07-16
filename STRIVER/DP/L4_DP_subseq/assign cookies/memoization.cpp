#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int recursion(vector<int>& g, vector<int>& s,int i,int j,
    vector<vector<int>>&dp){
        if(i>=g.size() || j>=s.size()){
            return 0;
        }
        
        if(dp[i][j] !=-1) return dp[i][j];

        if(g[i]<=s[j]){
            return 1 + recursion(g,s,i+1,j+1,dp);
        }
        else
        return dp[i][j] = recursion(g,s,i,j+1,dp);
    }    
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        vector<vector<int>>dp(g.size(),vector<int>(s.size(),-1));
        return recursion(g,s,0,0,dp);
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