#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p=1<<n;
        vector<vector<int>>ans(p);
        
        for(int i=0;i<p;i++)
        {
          for(int j=0;j<n;j++)
          {
            if((i>>j)&1)
            {
                ans[i].push_back(nums[j]);
            }
          }
        }
        return ans;
    }
};
////////////
/*
For 
𝑖
=
5
i=5 (binary: 101):

𝑗
=
0
j=0: (i >> 0) & 1 = 101 & 001 = 1 → Include nums[0].
𝑗
=
1
j=1: (i >> 1) & 1 = 10 & 001 = 0 → Do not include nums[1].
𝑗
=
2
j=2: (i >> 2) & 1 = 1 & 001 = 1 → Include nums[2].*/