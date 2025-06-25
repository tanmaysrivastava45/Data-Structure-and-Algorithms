#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
      int recursion(vector<int>& nums) {
         int n = nums.size();
        int prevs =0;
        int prev =nums[0];
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1)take += prevs;
            int nottake =prev;
            int curr=max(take,nottake);
            prevs = prev;
            prev = curr;
        }
        return prev;
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
        int one = recursion(ans1);
        int two = recursion(ans2);
        return max(one,two);
    }
};

int main(){
      Solution obj;
    vector<int> arr{2, 1, 4, 9};
    cout<<obj.rob(arr);
}