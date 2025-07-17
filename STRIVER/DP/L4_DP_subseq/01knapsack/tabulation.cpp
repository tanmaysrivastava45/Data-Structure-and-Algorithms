#include<bits/stdc++.h>
using namespace std; 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

    for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i]=value[0];
	}

    for(int i=1;i<n;i++){
		for(int j=0;j<=maxWeight;j++){
			int nottake = dp[i-1][j];

			// take 
			int take = 0;
			if(weight[i]<=j){
				take = value[i] + dp[i-1][j-weight[i]];
			}

			dp[i][j]=max(take,nottake);
		}
	}

    return dp[n-1][maxWeight];
}




int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}