#include <bits/stdc++.h> 
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i]=value[0];
	}
    for(int i=1;i<n;i++){
		for(int j=maxWeight;j>=0;j--){
			int nottake = prev[j];

			// take 
			int take = 0;
			if(weight[i]<=j){
				take = value[i] + prev[j-weight[i]];
			}

			prev[j]=max(take,nottake);
		}
	}

    return prev[maxWeight];
}

int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}