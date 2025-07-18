#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generate(int ind, int n , string temp, string& text1,vector<string>&s1){
        if(ind == n){
            s1.push_back(temp);
            return;
        }

        // nottake 
        generate(ind+1,n,temp,text1,s1);
        temp += text1[ind];
        generate(ind+1,n,temp,text1,s1);
        temp.pop_back();
    }
private:
    bool ispalindromic(string& s){
       int i = 0;
       int j = s.length()-1;
       while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
       }
       return true;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<string>ans;
        generate(0, n, "",s,ans);
        int res = 0;
        for(auto str : ans){
            if(ispalindromic(str)){
                res = max(res,(int)str.length());
            }
        }
        return res;
    }
};

int main() {
    string s1 = "bbbab";

    Solution obj;

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << obj.longestPalindromeSubseq(s1) << endl;

    return 0; // Return 0 to indicate successful program execution
}