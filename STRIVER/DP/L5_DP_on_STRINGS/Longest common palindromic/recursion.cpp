#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind1, int ind2, string& text1, string& text2){
       if(ind1<0 || ind2<0){
        return 0;
       }
       if(text1[ind1]==text2[ind2]){
          return 1+f(ind1-1,ind2-1,text1,text2);
       }
       else{
        return max(f(ind1-1,ind2,text1,text2),f(ind1,ind2-1,text1,text2));
       }
    } 
public:
    int longestPalindromeSubseq(string s) {
        string k = s;
        reverse(s.begin(),s.end());
        int n1 = s.length();
        int n2 = k.length();
        return f(n1-1,n2-1,s,k);
    }
};
int main() {
    string s1 = "bbbab";

    Solution obj;

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << obj.longestPalindromeSubseq(s1) << endl;

    return 0; // Return 0 to indicate successful program execution
}