#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int recursion(int n,vector<int>& nums){
       if(n<0)return 0;
       if(n==0)return nums[n];
       int left = nums[n]+recursion(n-2,nums);
       int right = recursion(n-1,nums);
       return max(left,right);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return recursion(n-1,nums);
    }
};
int main(){
   vector<int> arr{2, 1, 4, 9};
       Solution obj;
    // Call the solve function and print the result
    cout << obj.rob(arr);

}