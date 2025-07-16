#include <bits/stdc++.h> 
using namespace std;
int MOD = 1e9+7;

int recursion(int n, vector<int>&arr, int target, vector<vector<int>>&dp){
    if(n==0){
        if(target==0 && arr[0]==0)
        return 2;
        if(target==0)return 1;
        if(arr[n]==target)return 1;
        return 0;
    }
    if(dp[n][target]!=-1)return dp[n][target];
    int nottake = (recursion(n-1,arr, target,dp))%MOD;
    int take = 0;
    if(target>=arr[n]){
        take = (recursion(n-1,arr,target-arr[n], dp))%MOD;
    }
    return dp[n][target] = (nottake + take)%MOD;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(int i=0;i<n;i++){
        totsum += arr[i];
    }

    if(totsum<d)return 0;

    if((totsum-d)%2!=0)return 0;

    int target = (totsum-d)/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));

    return recursion(n-1,arr, target, dp);
}

int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
                                 
    cout<<"The number of subsets found are " <<countPartitions(4,d,arr);
}
