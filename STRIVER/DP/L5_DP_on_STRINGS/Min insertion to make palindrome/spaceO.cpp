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
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
        for(int i=0;i<=n1;i++){
            prev[0]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                  if(s[i-1]==k[j-1]){
                        curr[j] = 1+prev[j-1];
                    }
                    else{
                        curr[j] = max(prev[j],curr[j-1]);
                    }
            }
            prev = curr;
        }
        return n- prev[n2];
    }
};

int main() {
    string s = "abcaa";
    Solution obj;
    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << obj.minInsertions(s);
    return 0;
}