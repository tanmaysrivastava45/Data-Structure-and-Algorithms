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
    int minInsertions(string s) {
        int n = s.length();
        vector<string>ans;
        generate(0, n, "",s,ans);
        int res = 0;
        for(auto str : ans){
            if(ispalindromic(str)){
                res = max(res,(int)str.length());
            }
        }
        return n-res;
    }
};


int main() {
    string s = "abcaa";
    Solution obj;
    // Call the minInsertion function and print the result
    cout << "The Minimum insertions required to make string palindrome: " << obj.minInsertions(s);
    return 0;
}