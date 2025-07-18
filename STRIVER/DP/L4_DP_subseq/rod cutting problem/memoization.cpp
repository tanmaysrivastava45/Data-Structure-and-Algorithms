#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int>& price,int target, vector<vector<int>>&dp){
	if(ind==0){
		return price[0]*target;
	}
    if(dp[ind][target]!=-1)return dp[ind][target];
	int nottake = f(ind-1,price,target,dp);
	int take = 0;
	if(target>=ind+1){
		take = price[ind]+ f(ind,price,target-(ind+1),dp);
	}

	return dp[ind][target] = max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,price,n,dp);
}
int main() {
    vector<int> price = {3, 5 ,8, 9, 10, 17 ,17 ,20}; // price of rod parts
    int n = 8;
    cout << "The Maximum value of items the thief can steal is " << cutRod(price,n) << endl;

    return 0;
}