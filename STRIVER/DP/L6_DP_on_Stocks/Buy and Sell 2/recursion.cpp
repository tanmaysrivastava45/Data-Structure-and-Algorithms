
#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int f(int ind, int buy, vector<int>& prices, int n, int profit){
        if(ind == n)return 0;
        if(buy ==1){
          profit = max(-prices[ind]+f(ind+1,0,prices,n,profit),f(ind+1,1,prices,n,
          profit));
        }else{
            profit = max(prices[ind]+f(ind+1,1,prices,n,profit),f(ind+1,0,prices,n,
            profit));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit;
        return f(0,1,prices,n,profit);
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
