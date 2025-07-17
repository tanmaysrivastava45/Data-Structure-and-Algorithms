#include<bits/stdc++.h>
using namespace std;


class Solution {
int MOD = 1e9+7;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        for(int i=0;i<=amount;i++){
             if(i%coins[0]==0){
                prev[i]=1;
             }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                    long long nottake = prev[j];
                    long long take = 0;
                    if(j>=coins[i]){
                        take = curr[j-coins[i]];
                    }
                    if(take+nottake>INT_MAX){
                        curr[j] = (take + nottake)%MOD;
                    }else
                    curr[j] = 1LL*(take + nottake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    Solution obj;

    cout << "The total number of ways is " << obj.change(target,arr) << endl;

    return 0; // Return 0 to indicate successful program execution
}