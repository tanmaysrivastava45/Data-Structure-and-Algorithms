#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int>& price,int target){
	if(ind==0){
		return price[0]*target;
	}

	int nottake = f(ind-1,price,target);
	int take = 0;
	if(target>=ind+1){
		take = price[ind]+ f(ind,price,target-(ind+1));
	}

	return max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return f(n-1,price,n);
}
int main() {
    vector<int> price = {3, 5 ,8, 9, 10, 17 ,17 ,20}; // price of rod parts
    int n = 8;
    cout << "The Maximum value of items the thief can steal is " << cutRod(price,n) << endl;

    return 0; 
}