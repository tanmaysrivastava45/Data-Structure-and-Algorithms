#include<bits/stdc++.h>
using namespace std;
// two methods two solve this problem one is to copy the array and the other is
// to traverse the whole array and printing non zero elements first and then zeros

// 1) copy of array

// vector<int> moveZeroes(vector<int>& nums) {
//     vector<int> result(nums.size()); // Create a new vector with the same size as nums
//     int index = 0;
    
//     // First pass: Copy all non-zero elements to the result vector
//     for (int num : nums) {
//         if (num != 0) {
//             result[index++] = num;
//         }
//     }
    
//     // Second pass: Fill the rest of the result vector with zeros
//     while (index < result.size()) {
//         result[index++] = 0;
//     }
    
//     return result;
// }

// 2) traversing of array 

vector<int> moveZeroes(vector<int>& nums)
{
  int j=0;
  for(int i=0;i<nums.size();i++)
  {
    if(nums[i]!=0)
    {
        swap(nums[j],nums[i]);
        j++;
    }
  }
}

void print(vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    
    // vector<int> result =
     moveZeroes(nums);
    
    print(nums); // Output: 1 3 12 0 0
    
    return 0;
}
