#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>prev(w+1,0);
    for(int i=weight[0];i<=w;i++){
        prev[i] = (i/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int nottake = 0 + prev[j];
            int take = 0;
            if(weight[i]<=j){
                take = profit[i] + prev[j-weight[i]];
            }
            prev[j] = max(take,nottake);
        }
       
    }
    return prev[w];
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}