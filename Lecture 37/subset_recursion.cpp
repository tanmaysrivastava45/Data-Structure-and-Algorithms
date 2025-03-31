#include<iostream>
#include<vector>
using namespace std;
class Solution {
private : 
    void subsets(vector<vector<int>>& ans,vector<int>temp,int idx,vector<int>&nums)
    {
        if(idx>= nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        ///  exclude

        subsets(ans,temp,idx+1,nums);

        // include
        temp.push_back( nums[idx]);
        subsets(ans,temp,idx+1,nums);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int idx=0;
        vector<vector<int>>ans;
        vector<int>temp;
        subsets(ans,temp,idx,nums);
        return ans;
    }
};