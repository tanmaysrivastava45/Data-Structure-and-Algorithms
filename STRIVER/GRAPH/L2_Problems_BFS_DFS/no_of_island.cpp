#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
      void bfs(int row, int col, vector<vector<int>>& visited, 
   vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int l = -1;l<=1;l++){
        for (int k = -1; k <=1; k++) {
            int ni = i + l;
            int nj = j + k;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !visited[ni][nj] && grid[ni][nj] == 'L') {
                visited[ni][nj] = 1;
                q.push({ni, nj});
            }
        }}
    }
}

  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
            
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='L'){
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};

int main(){
 
 
    vector<vector<char>> grid = {{'L', 'L', 'W', 'W', 'W'}, {'W', 'L', 'W', 'W', 'L'}, 
    {'L', 'W', 'W', 'L', 'L'}, {'W', 'W', 'W', 'W', 'W'}, {'L', 'W', 'L', 'L', 'W'}};

    Solution obj;
    cout<<obj.countIslands(grid);
}