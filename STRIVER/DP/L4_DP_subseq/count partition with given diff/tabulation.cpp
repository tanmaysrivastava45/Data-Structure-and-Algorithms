#include <bits/stdc++.h> 
using namespace std;

int MOD = 1e9+7;


int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(int i=0;i<n;i++){
        totsum += arr[i];
    }

    if(totsum<d)return 0;

    if((totsum-d)%2!=0)return 0;

    int target = (totsum-d)/2;
    vector<vector<int>>dp(n,vector<int>(target+1,0)); 
    
    if(arr[0]==0)dp[0][0]=2;
    else
    dp[0][0]=1;

    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=0;j<= target;j++){
            int nottake = (dp[i-1][j])%MOD;
            int take = 0;
            if(j>=arr[i]){
                take = (dp[i-1][j-arr[i]])%MOD;
            }
           dp[i][j] = (nottake + take)%MOD;
        }
    }

    return dp[n-1][target];
}
int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
                                 
    cout<<"The number of subsets found are " <<countPartitions(4,d,arr);
}

