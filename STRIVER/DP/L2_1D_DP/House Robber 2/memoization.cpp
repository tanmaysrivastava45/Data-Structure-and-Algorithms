#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    int recursion(int n,vector<int>&nums){
        if(n<0)return 0;
        if(n==0)return nums[n];
        int take = nums[n]+recursion(n-2,nums);
        int nottake = recursion(n-1,nums);
        return max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>ans1;
        vector<int>ans2;
        for(int i=0;i<n;i++){
            if(i!=0){
                ans1.push_back(nums[i]);
            }
            if(i!=n-1){
                ans2.push_back(nums[i]);
            }
        }
        int one = recursion(ans1.size()-1,ans1);
        int two = recursion(ans2.size()-1,ans2);
        return max(one,two);
    }
};
int main(){
      Solution obj;
    vector<int> arr{2, 1, 4, 9};
    cout<<obj.rob(arr);
}