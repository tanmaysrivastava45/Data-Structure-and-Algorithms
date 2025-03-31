#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
   
    vector<int>ans;
   
    
    for(int cols=0;cols<mCols;cols++)
    {
        if(cols%2==0)
        {
          for (int rows = 0; rows < nRows; rows++) {
            ans.push_back(arr[rows][cols]);
          }
        }
        else{
            for (int rows = 0; rows < nRows; rows++) {
            ans.push_back(arr[nRows-rows-1][cols]);
          }
        }
    }
    return ans;
}
