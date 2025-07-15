#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
      bool recursion(int i,vector<int>&arr,int sum,int k){
          if(sum==k){
            return true;
          }
          if(i==arr.size())return false;
          bool take  = recursion(i+1,arr,arr[i]+sum,k);
          bool nottake  = recursion(i+1,arr,sum,k);
          return take || nottake;
      }
    public:
      bool subsetsum(vector<int>&arr,int k){
        return recursion(0,arr,0,k);
      }
};

int main(){
 vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    Solution obj;

    // Call the subsetSumToK function and print the result
    if (obj.subsetsum(arr,k))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}