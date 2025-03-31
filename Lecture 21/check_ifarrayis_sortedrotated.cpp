// #include<bits/stdc++.h>
// using namespace std;

//  bool check(vector<int>& nums) {
//          int n=nums.size();
//         int count =0;
//         for(int i=1;i<n;i++)
//         {
//           if(nums[i-1]>nums[i])
//           {
//               count++;
//           }
            
//         }
//         if(nums[n-1]>nums[0])
//         {
//             count++;
//         }
//         return count<=1;
        
//     }
// int main()
// {
//     vector<int> arr={3,4,5,1,2};
// bool isRotatedSorted = check(arr);
    
//     // Print the result
//     if (isRotatedSorted) {
//         cout << "The array is a rotated sorted array." << endl;
//     } else {
//         cout << "The array is not a rotated sorted array." << endl;
//     }
//     }
#include<bits/stdc++.h>
using namespace std;

 void check(vector<int>nums) {
         int n=nums.size();
        int count =0;
        for(int i=1;i<n;i++)
        {
          if(nums[i-1]>nums[i])
          {
              count++;
          }
            
        }
        if(nums[n-1]>nums[0])
        {
            count++;
        }
        if(count<=1)
        {
            cout<<"YES";

        }
        else{cout<<"NO";}
    }
int main()
{
    vector<int> arr={3,4,5,1,2};
    check(arr);
}
