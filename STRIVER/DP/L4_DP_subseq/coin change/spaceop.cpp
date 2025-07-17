#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
            prev[i]=i/coins[0];
            else
            prev[i]=1e9;

        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake = prev[j];
                int take = 1e9;
                if(j>=coins[i]){
                   take = 1 + curr[j-coins[i]];
                }

              curr[j] = min(take,nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return (ans>=1e9)? -1 : ans;
    }
};


int main() {
    vector<int> arr = {1, 2, 3};
    int T = 7;
    
    // Call the function to find the minimum number of elements needed
    Solution obj;
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << obj.coinChange(arr,T) << endl;
    
    return 0; // Return 0 to indicate successful program execution
}