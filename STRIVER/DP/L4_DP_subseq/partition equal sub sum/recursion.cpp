#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursion(vector<int>&nums, int target, int sum, int n){
        if(n<0)return false;
        if(sum==target)return true;
        bool take = recursion(nums,target,sum+nums[n],n-1);
        bool nottake = recursion(nums,target,sum,n-1);
        return take|| nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0)return false;
        return recursion(nums,sum/2,0,n-1);
    }
};

int main(){
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();
    Solution obj;
    if (obj.canPartition(arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}