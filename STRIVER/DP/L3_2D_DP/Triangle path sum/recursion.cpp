#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int recursion(int i,int j,vector<vector<int>>& triangle,int n){
        if(i==n-1){
            return triangle[i][j];
        }
        int left = recursion(i+1,j,triangle,n);
        int up = recursion(i+1,j+1,triangle,n);
        return triangle[i][j]+min(left,up);
    }   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        return recursion(0,0,triangle,n);
    }
};
int main() {
    // Define the triangle as a 2D vector
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    Solution obj;
    // Call the minimumPathSum function and print the result
    cout << obj.minimumTotal(triangle);

    return 0;
}
