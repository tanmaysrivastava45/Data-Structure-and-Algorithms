#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    if(k>=arr[0])
    dp[0][arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int take = 0;
            int nottake = (dp[i-1][j])%MOD;

            if(j>=arr[i]){
            take = (dp[i-1][j-arr[i]])%MOD;
            }

            dp[i][j]= (take+ nottake)%MOD;
        }
    }
	return dp[n-1][k];
}
int main(){
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}