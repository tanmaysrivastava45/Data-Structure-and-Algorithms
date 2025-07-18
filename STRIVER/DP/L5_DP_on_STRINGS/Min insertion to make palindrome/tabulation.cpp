#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
         string k = s;
        reverse(s.begin(),s.end());
        int n1 = s.length();
        int n2 = k.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                  if(s[i-1]==k[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
            }
        }
        return n-dp[n1][n2];
    }
};


int main() {
    string s = "abcaa";
    Solution obj;
    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << obj.minInsertions(s);
    return 0;
}