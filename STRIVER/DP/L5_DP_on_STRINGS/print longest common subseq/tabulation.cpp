#include<bits/stdc++.h>
using namespace std;

string findLCS(int n1, int n2,string &text1, string &text2){
	// Write your code here.
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
        int len = dp[n1][n2];
		string ans = "";
		for(int i=0;i<len;i++){
			ans += '$';
		}
		int idx = len-1;
        int i=n1;
        int j=n2;
	    while(i>0 && j>0){
			if(text1[i-1]==text2[j-1]){
               ans[idx]=text1[i-1];
			   idx--;
			   i--;
			   j--;
			}else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else j--;
		}
        return ans;
}


int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is ";
  cout<<findLCS(s1.length(), s2.length(),s1,s2);
}