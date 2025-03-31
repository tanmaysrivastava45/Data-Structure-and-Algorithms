#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int r=matrix.size();
//         int c=matrix[0].size();
         
//         for(int i=0;i<r;i++)
//         {
//             for(int j=0;j<c;j++)
//             { if(matrix[i][j]==target)
//             {
//                 return true;
//             }}
//         }
//         return false;
        
        // int row=0;
        // int col=c-1;
        // while(row<r && col>=0)
        // {
        //     int ele=matrix[row][col];
        //     if(ele==target)
        //     {
        //         return 1;
        //     }
        //     else if(ele<target)
        //     {
        //         row++;
        //     }
        //     else{
        //         col--;
        //     }
        // }
        // return 0;
         int row=0;
        int col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};