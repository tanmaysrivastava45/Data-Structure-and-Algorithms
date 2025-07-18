#include<bits/stdc++.h>
using namespace std;

int recursion(int ind, int maxw, vector<int>&profit, vector<int>&weight,vector<vector<int>>&dp){
    if(ind == 0){
        return (maxw/weight[0])*profit[0];
    }
    if(dp[ind][maxw]!=-1)return dp[ind][maxw];
    int nottake = 0 + recursion(ind-1,maxw,profit,weight,dp);
    int take = 0;
    if(weight[ind]<=maxw){
        take = profit[ind] + recursion(ind,maxw-weight[ind],profit,weight,dp);

    }
    return dp[ind][maxw] = max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return recursion(n-1,w,profit,weight,dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}