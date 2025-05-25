#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct TNode{
    int val;
    TNode* left;
    TNode* right;
    TNode(int data){
        val=data;
        left = NULL;
        right = NULL;
    }
};
vector<int>postorder(TNode* &root){
        stack<TNode*>st;
        TNode* curr = root;
        vector<int>ans;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
              TNode* temp = st.top()->right;
              if(temp ==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
              }else{
                curr = temp;
              }
            }
        }
        return ans;
}

int main(){
    TNode* root = new TNode(1);
    root->left = new TNode(5);
    root->right =new TNode(4);
    root ->left ->left = new TNode(6);
    root->left->right = new TNode(9);

    vector<int>ans = postorder(root);
    cout<<"Post Order traversal :";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}