#include<bits/stdc++.h>
using namespace std;

class Disjoint{
vector<int>rank;
vector<int>parent;
public:
  Disjoint(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
  }

  int findUparent(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node]=findUparent(parent[node]);
  }

  void unionByRank(int u,int v){
    // ultimate parent of u and v
    int ul_p_u = findUparent(u);
    int ul_p_v = findUparent(v);
    if(ul_p_u==ul_p_v)return;
    if(rank[ul_p_u]==rank[ul_p_v]){
        parent[ul_p_u]=ul_p_v;
        rank[ul_p_v]++;
    }
    else if(rank[ul_p_u]<rank[ul_p_v]){
        parent[ul_p_u]=ul_p_v;
    }
    else if(rank[ul_p_u]>rank[ul_p_v]){
        parent[ul_p_v]=ul_p_u;
    }
    
  }
};


int main(){
  Disjoint obj(7);
  obj.unionByRank(1,2);
  obj.unionByRank(2,3);
  obj.unionByRank(4,5);
  obj.unionByRank(6,7);
  obj.unionByRank(5,6);
  if(obj.findUparent(3)==obj.findUparent(7)){
    cout<<"same"<<endl;
  }else cout<<"not same"<<endl;
  obj.unionByRank(3,7);
 if(obj.findUparent(3)==obj.findUparent(7)){
    cout<<"same"<<endl;
  }else cout<<"not same"<<endl;
}