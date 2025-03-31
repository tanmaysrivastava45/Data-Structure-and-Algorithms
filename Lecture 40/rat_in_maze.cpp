#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool safe(int currx,int curry,vector<vector<int>> &map,vector<vector<int>> &mat,int n)
    {
        if((currx>=0 && currx<n)&& (curry>=0 && curry<n) && map[currx][curry]==0 && mat[currx][curry]==1 )
        {
            return true;
        }
        else{
            return false;
        }
    }
  private: 
    void solve(int sx,int sy,vector<vector<int>> &mat,string path,int n,vector<string>&ans,vector<vector<int>> &map)
    {
        // base case
        if(sx==n-1 && sy==n-1)
        {
            ans.push_back(path);
            return ;
        }
        map[sx][sy]=1;
        // down 
        int currx=sx+1;
        int curry=sy;
        if(safe(currx,curry,map,mat,n))
        {
            path.push_back('D');
            solve(currx,curry,mat,path,n,ans,map);
            path.pop_back();
        }
        // left
        currx=sx;
        curry=sy-1;
        if(safe(currx,curry,map,mat,n))
        {
            path.push_back('L');
            solve(currx,curry,mat,path,n,ans,map);
            path.pop_back();
        }
        // right
        currx=sx;
        curry=sy+1;
        if(safe(currx,curry,map,mat,n))
        {
            path.push_back('R');
            solve(currx,curry,mat,path,n,ans,map);
            path.pop_back();
        }
        // up
        currx=sx-1;
        curry=sy;
        if(safe(currx,curry,map,mat,n))
        {
            path.push_back('U');
            solve(currx,curry,mat,path,n,ans,map);
            path.pop_back();
        }
        
        map[sx][sy]=0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        vector<string>ans;
        int sx=0;
        int sy=0;
        if(sx==0 && sy==0 &&mat[0][0]==0)
        {
            return ans;
        }
        vector<vector<int>>map=mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                map[i][j]=0;
            }
        }
        string path ="";
        solve(sx,sy,mat,path,n,ans,map);
        sort(ans.begin(),ans.end());
        return ans;
    }
};