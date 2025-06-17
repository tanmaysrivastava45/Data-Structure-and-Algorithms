#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int>size,parent;
    public:
    Disjoint(int n){
        size.resize(n+1,1);
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
    void UnionBySize(int u,int v){
        // finding the ultimate parent of node u and v
        int ul_p_u = findUparent(u);
        int ul_p_v = findUparent(v);

        if(ul_p_u==ul_p_v)return;
        else if(size[ul_p_u]<size[ul_p_v]){
            parent[ul_p_u]=ul_p_v;
            size[ul_p_v]+= size[ul_p_u];
        }
        else if(size[ul_p_v]<size[ul_p_u]){
            parent[ul_p_v]=ul_p_u;
            size[ul_p_u]+= size[ul_p_v];
        }else{
            parent[ul_p_u]=ul_p_v;
            size[ul_p_v]+= size[ul_p_u];
        }
    }
};

int main(){
    Disjoint ds(7);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUparent(3) == ds.findUparent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.UnionBySize(3, 7);

    if (ds.findUparent(3) == ds.findUparent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;

}