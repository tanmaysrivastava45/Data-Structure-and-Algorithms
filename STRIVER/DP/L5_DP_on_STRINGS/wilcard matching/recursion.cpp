#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int i, int j, string& s, string& p){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(j<0 && i>=0){
            for(int k =0;k<=i;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(s[j]==p[i]  || p[i]=='?'){
           return f(i-1,j-1,s,p);
        }
        if(p[i]=='*'){
           return f(i-1,j,s,p) || f(i,j-1,s,p);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return f(m-1,n-1,s,p);
    }
};