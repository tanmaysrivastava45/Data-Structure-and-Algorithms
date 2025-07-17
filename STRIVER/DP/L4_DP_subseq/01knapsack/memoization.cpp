#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 

int recursion(int ind,int wt,vector<int>&weight,vector<int>&value,int n,int maxWeight,vector<vector<int>>&dp){

if(ind==0){
	if(weight[0]<=wt){
         return value[ind];
	}else{
		return 0;
	}
}


if(dp[ind][wt]!=-1)return dp[ind][wt];

// nottake 
int nottake = 0+ recursion(ind-1,wt,weight,value,n,maxWeight,dp);

// take 
int take = 0;
if(weight[ind]<=wt){
	take = value[ind] + recursion(ind-1,wt-weight[ind],weight,value,n,maxWeight,dp);
}
return dp[ind][wt] = max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    return recursion(n-1,maxWeight,weight,value,n,maxWeight,dp);
}



int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}