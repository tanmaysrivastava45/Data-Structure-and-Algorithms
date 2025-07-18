#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                  if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
            }
        }
        return dp[n1][n2];
    }
};


int main() {
    string s1 = "acd";
    string s2 = "ced";

    Solution obj;

    cout << "The Length of Longest Common Subsequence is " << obj.longestCommonSubsequence(s1, s2) << endl;

} 