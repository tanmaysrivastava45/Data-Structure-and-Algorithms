#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int count=0;
        int total=rows*cols;
        int startingrow=0;
        int endingrow=rows-1;
        int startingcols=0;
        int endingcols=cols-1;
        while(count<total)
        {   
            // printing start row
            for(int i=startingcols;count<total && i<=endingcols;i++) // added the condition of count<total so that it does not stuck in loop and do unexpected stuffs
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
             startingrow++;
            // printing lastcol
            for(int i=startingrow;count<total && i<=endingrow;i++)
            {
                ans.push_back(matrix[i][endingcols]);
                count++;
            }
                endingcols--;
            // printing last row
            for(int i=endingcols;count<total && i>=startingcols;i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            
                endingrow--;
            //printing start cols
            for(int i=endingrow;count<total && i>=startingrow;i--)
            {
                ans.push_back(matrix[i][startingcols]);
                count++;
            }
            
                startingcols++;
            
        }
            return ans;
       
    }
};