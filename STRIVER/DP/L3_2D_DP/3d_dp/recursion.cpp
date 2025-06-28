#include <bits/stdc++.h>
using namespace std;
int recursion(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid){
    if(j1<0 || j2<0 || j1>=c || j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2){
            return grid[i][j1];
        }else {
            return grid[i][j1]+grid[i][j2];
        }
    }
   int maxi = 0;
   for(int dx =-1;dx<=1;dx++){
       for(int dy=-1;dy<=1;dy++){
           int val =0;
           if(j1==j2){
               val = grid[i][j1];
           }
           else{
               val = grid[i][j1]+grid[i][j2];
           }
           val += recursion(i+1,j1+dx,j2+dy,r,c,grid);
           maxi = max(maxi,val);
       }

   }
   return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return recursion(0,0,c-1,r,c,grid);
}

int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}