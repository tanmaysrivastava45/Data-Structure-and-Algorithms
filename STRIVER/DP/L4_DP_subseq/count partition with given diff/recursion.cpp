#include<bits/stdc++.h>
using namespace std;

int recursion(int n, vector<int>&arr, int target){
    if(n==0){
        if(target==0 && arr[0]==0)
        return 2;
        if(target==0)return 1;
        if(arr[n]==target)return 1;
        return 0;
    }

    int nottake = recursion(n-1,arr, target);
    int take = 0;
    if(target>=arr[n]){
        take = recursion(n-1,arr,target-arr[n]);
    }
    return nottake + take;
}

int countpartition(int d, vector<int>&arr){
    int totsum = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        totsum += arr[i];
    }

    if(totsum<d)return 0;

    if((totsum-d )%2!=0)return 0;

    int target = (totsum-d)/2;
     
    return recursion(n-1,arr, target);
}

int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
                                 
    cout<<"The number of subsets found are " <<countpartition(d,arr);
}