#include<bits/stdc++.h>
using namespace std;



int LCSubStr(string &text1, string &text2)
{
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }
        int ans = 0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                  if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                        ans = max(ans,dp[i][j]);
                    }
                    else{
                        dp[i][j] = 0;
                    }
            }
        }
        return ans;

}


int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << "The Length of Longest Common Substring is " << LCSubStr(s1, s2) << endl;

}