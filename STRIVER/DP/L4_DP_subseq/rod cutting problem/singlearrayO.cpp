#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>prev(n+1,0);
	for(int i=0;i<=n;i++){
        prev[i] = price[0]*i;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
            int nottake = prev[j];
			int take = 0;
			if(j>=i+1){
				take = price[i]+ prev[j-(i+1)];
			}
            prev[j] = max(take,nottake);
		}
	}
	return prev[n];
}
int main() {
    vector<int> price = {3, 5 ,8, 9, 10, 17 ,17 ,20}; // price of rod parts
    int n = 8;
    cout << "The Maximum value of items the thief can steal is " << cutRod(price,n) << endl;

    return 0; 
}