#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void comb(string digits,vector<string>& ans,int i,string temp)
    {
         string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(i>=digits.length())
        {
            ans.push_back(temp);
            return ;
        }
        int ele = digits[i]-'0';
        string val = map[ele];
        for(int j=0;j<val.length();j++)
        {
          temp.push_back(val[j]);
          comb(digits,ans,i+1,temp);
          temp.pop_back(); 
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int i=0;
        string temp="";
        if(digits.length()==0)
        {
            return ans;
        }
        comb(digits,ans,i,temp);
        return ans;
    }
};