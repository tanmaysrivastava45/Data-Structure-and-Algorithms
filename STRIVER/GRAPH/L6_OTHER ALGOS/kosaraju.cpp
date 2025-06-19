//Position this line where user code will be pasted.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: 
      void dfs(int it,vector<int>&visited,vector<vector<int>> &adj,
      stack<int>&st){
          visited[it]=1;
          for(auto i : adj[it]){
              if(!visited[i]){
                  dfs(i,visited,adj,st);
              }
          }
          
          st.push(it);
      }
      private: 
      void dfs2(int i,vector<int>&visited,vector<int> rev[]){
          visited[i]=1;
          for(auto it : rev[i]){
              if(!visited[it]){
                  dfs2(it,visited,rev);
              }
          }
      }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>visited(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>rev[n];
        // reverse the graph 
        for(int i=0;i<n;i++){
                visited[i]=0;
            for(auto it: adj[i]){
                rev[it].push_back(i);
            }
        }
        // stack empty count krna hai components ko
        int count = 0;
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            if(!visited[ele]){
                count++;
            dfs2(ele,visited,rev);
            }
        }
        return count;
    }
};
int main(){
    vector<vector<int>> adj = {
        {2,3},
        {0},
        {1},
        {4},
        {}
    };
    Solution obj;
    cout<<obj.kosaraju(adj)<<endl;
}