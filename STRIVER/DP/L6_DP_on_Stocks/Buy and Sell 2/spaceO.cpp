
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        vector<int>ahead(2,0),curr(2,0);
        ahead[0]=0;
        ahead[1]=0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                 if(buy ==1){
                    profit = max(-prices[ind]+ahead[0],ahead[1]);
                }else{
                    profit = max(prices[ind]+ahead[1],ahead[0]);
                }
                 curr[buy] = profit;
            }
            ahead = curr;       
        }
        return ahead[1];
    }
};

int main() {
    int n = 6;
    vector<int>Arr = {7, 1, 5, 3, 6, 4};
    Solution obj;
    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << obj.maxProfit(Arr);

    return 0;
}
