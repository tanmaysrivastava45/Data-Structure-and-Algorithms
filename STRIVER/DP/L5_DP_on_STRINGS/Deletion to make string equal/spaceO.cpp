#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
        for(int i=0;i<=n1;i++){
            prev[0]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                  if(text1[i-1]==text2[j-1]){
                        curr[j] = 1+prev[j-1];
                    }
                    else{
                        curr[j] = max(prev[j],curr[j-1]);
                    }
            }
            prev = curr;
        }
        return prev[n2];
    }
public:
    int minDistance(string word1, string word2) {
       int a = longestCommonSubsequence(word1,word2);
       int n = word1.length();
       int m = word2.length();
       return (n+m)-(2*a);
    }
};

int main() {
    string str1 = "abcd";
    string str2 = "anc";
    Solution obj;
    cout << "The Minimum operations required to convert str1 to str2: " << obj.minDistance(str1, str2);
    return 0;
}