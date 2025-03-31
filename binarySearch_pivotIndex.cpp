
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int start=0;
//         int n=nums.size();
//         int end = n-1;
//         int mid= start+(end-start)/2;
//         int sum1=0;
//         int sum2=0;
//         while(start<=end)
//         {
//         for(int i=0;i<mid;i++)
//         {
//             sum1=sum1+nums[i];
//         }
//         for(int i=mid+1;i<=end;i++)
//         {
//             sum2=sum2+nums[i];
//         }
//         if(sum1==0||sum2==0)
//         {
//             return -1;
//         }
//         else if(sum1<sum2)
//         {
//             mid=mid+1;
//         }
//         else if(sum1>sum2)
//             {
//                 mid=mid-1;
//             }
//         else if(sum1==sum2)
//         {
//             return mid;
//         }
//             mid=start+(end-start)/2;
//         }
//         return mid;
//     }
// };
#include<iostream>
#include<vector>
using namespace std;

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int leftSum = 0;

        // Compute the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Traverse the array to find the pivot index
        for (int i = 0; i < n; ++i) {
            // Check if the left sum equals the right sum
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            // Update the left sum for the next iteration
            leftSum += nums[i];
        }

        // Return -1 if no pivot index is found
        return -1;
    }
     
    int main()
    {
        vector<int> ans;
        ans={1,7,3,6,5,6};
      
       cout<< pivotIndex(ans);
    } 
