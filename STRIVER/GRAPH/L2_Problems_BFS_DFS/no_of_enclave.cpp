#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(!visited[0][i] && grid[0][i]==1){
                visited[0][i]=1;
                q.push({0,i});
            }
            if(!visited[n-1][i] && grid[n-1][i]==1){
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(!visited[i][m-1] && grid[i][m-1]){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int arr1[]={-1,0,1,0};
            int arr2[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]
                   && grid[nrow][ncol]==1)
                {
                   q.push({nrow,ncol});
                   visited[nrow][ncol]=1;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
// Sample test case
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Number of Enclaves: " << sol.numEnclaves(grid) << endl;
    return 0;
}
