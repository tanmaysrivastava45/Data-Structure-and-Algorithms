#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int ind, vector<int>& coins, int target){
        // base case
        if(ind==0){
            if(target%coins[0]==0){
                return target/coins[0];
            }else{
                return 1e9;
            }
        }

       int nottake = recursion(ind-1,coins,target);
       int take = 1e9;
       if(target>=coins[ind]){
          take = 1 + recursion(ind,coins,target-coins[ind]);
       }

       return min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = recursion(n-1,coins,amount);
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