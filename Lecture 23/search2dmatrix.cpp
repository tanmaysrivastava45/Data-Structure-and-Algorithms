#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r=matrix.size();
        int c=matrix[0].size();
        // brute force approach 
        // for(int i=0;i<r;i++)
        // {
        //     for(int j=0;j<c;j++)
        //     { if(matrix[i][j]==target)
        //     {
        //         return true;
        //     }}
        // }
        // return false;
        
        // binary search 
        int s=0;
        int e=r*c-1;
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            
            int ele=matrix[mid/c][mid%c];
            if(ele==target)
            {
                return true;
            }
            if(ele<target)
            {
                 s=mid+1;
            }
            else{
               e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};