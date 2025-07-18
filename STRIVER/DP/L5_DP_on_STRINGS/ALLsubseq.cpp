#include<bits/stdc++.h>
using namespace std;

void f(int ind,int n,vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp){
    if(n==ind){
        ans.push_back(temp);
        return ;
    }
    f(ind+1,n,arr,ans,temp);
    temp.push_back(arr[ind]);
    f(ind+1,n,arr,ans,temp);
    temp.pop_back();
}

vector<vector<int>> print(vector<int>&arr){
    vector<vector<int>>ans;
    vector<int>temp;
    int n = arr.size();
    f(0,n,arr,ans,temp);
    return ans;
}

int main(){
    vector<int> arr ={1,2,3};
    vector<vector<int>>ans = print(arr);
      for(int i=0;i<ans.size();i++){
        for(int j=0;j< ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}