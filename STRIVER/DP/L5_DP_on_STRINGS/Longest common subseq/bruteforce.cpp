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
    bool issame(string &a,string& b){
        return (a==b);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<string>s1;
        vector<string>s2;
        generate(0,text1.length(),"",text1,s1);
        generate(0,text2.length(),"",text2,s2);

        int maxi = 0;
        for(auto ita: s1){
            for(auto itb : s2){
                 if(issame(ita,itb)){
                    maxi = max(maxi,(int)ita.length());
                 }
            }
        }
        return maxi;
    }
};


int main() {
    string s1 = "acd";
    string s2 = "ced";

    Solution obj;

    cout << "The Length of Longest Common Subsequence is " << obj.longestCommonSubsequence(s1, s2) << endl;

} 