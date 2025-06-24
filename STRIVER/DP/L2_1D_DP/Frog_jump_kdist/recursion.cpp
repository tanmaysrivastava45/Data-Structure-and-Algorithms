#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    int recursion(int n, vector<int>&height,int k){
        if(n==0)return 0;
        int mini = INT_MAX;
        for(int j= 1;j<=k;j++){
            if(n-j>=0){
            int jump = recursion(n-j,height,k) + abs(height[n]-height[n-j]);
            mini = min(mini,jump);
            }
        }
        return mini;
    }
    public:
    int min_cost(vector<int>&height,int k){
        int n = height.size();
        return recursion(n-1,height,k);
    }
};

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    Solution obj;
    cout << obj.min_cost( height, k) << endl; // Print the result of the solve function
    return 0;
}