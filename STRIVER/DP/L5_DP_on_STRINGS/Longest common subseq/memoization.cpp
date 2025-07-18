#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind1, int ind2, string& text1, string& text2,vector<vector<int>>&dp){
       if(ind1<0 || ind2<0){
        return 0;
       }
       if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
       if(text1[ind1]==text2[ind2]){
          return 1+f(ind1-1,ind2-1,text1,text2,dp);
       }
       else{
        return dp[ind1][ind2] = max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
       }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,text1,text2,dp);
    }
};


int main() {
    string s1 = "acd";
    string s2 = "ced";

    Solution obj;

    cout << "The Length of Longest Common Subsequence is " << obj.longestCommonSubsequence(s1, s2) << endl;

} 