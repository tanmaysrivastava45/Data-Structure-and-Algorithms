#include<bits/stdc++.h>
using namespace std;
int recursion(int ind, vector<int>&arr, int k, vector<vector<int>>&dp){
    if(k==0)return 1;
	if(ind == 0) {
    if(k == 0 && arr[0] != 0) return 1; 
    if(k == arr[0]) return 1;
    return 0;
    }
    if(dp[ind][k]!=-1)return dp[ind][k];
    int take = 0;
	int nottake = recursion(ind-1,arr,k,dp);

	if(k>=arr[ind]){
    take = recursion(ind-1,arr,k-arr[ind],dp);
	}

	return dp[ind][k]= take+ nottake;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return recursion(n-1,arr,k,dp);
}

int main(){
    vector<int>arr={1,2,2,3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);


}