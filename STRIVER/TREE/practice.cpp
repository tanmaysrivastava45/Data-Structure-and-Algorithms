#include<bits/stdc++.h>
using namespace std;

/// tree build 
// Inorder traversal: Left -> Root -> Right
// Tree:
//         5
//       /   \
//      2     3
//     / \   / \
//    1   4 7   8
// Inorder   : 1 2 4 5 7 3 8
// preorder  : 5 2 1 4 3 7 8
// postorder : 1 4 2 7 8 3 5 
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left  = NULL;
        right = NULL;
    }
};
class Solution {
    // vector<int> Traversal(Node* root){
    //     stack<Node*>st;
    //     vector<int>ans;
    //     Node* temp = root;
    //     st.push(root);
    //     while(!st.empty()){
    //        temp = st.top();
    //        st.pop();
    //        ans.push_back(temp->val);
    //        if(temp->right!=NULL){
    //         st.push(temp->right);
    //        }
    //        if(temp->left!=NULL){
    //         st.push(temp->left);
    //        }
    //     }
    //     return ans;
    // }
    // vector<int> inorder(Node* root){
    //     stack<Node*>st;
    //     vector<int>ans;
    //     st.push(root);
    //     Node* temp = root;
    //     while (temp!=nullptr || !st.empty())
    //     {
    //         if(temp!=nullptr){
    //             st.push(temp);
    //             temp = temp -> left;
    //         }else{
    //             temp= st.top();
    //             st.pop();
    //             ans.push_back(temp->val);
    //             temp = temp->right;
    //         }
    //     }
    //     return ans;
    // }
    // public:
    // vector<int>preorder(Node* root){
    //     stack<Node*>st;
    //     vector<int>ans;
    //     st.push(root);
    //     Node* temp = root;
    //     while(!st.empty() && temp!=nullptr){
    //         temp = st.top();
    //         st.pop();
    //         ans.push_back(temp->val);
    //         if(temp->right!=nullptr){
    //         st.push(temp->right);
    //         }
    //         if(temp->left!=nullptr){
    //         st.push( temp->left);
    //         }
    //     }
    //     return ans;
    // }

    // public:
    // vector<int>postorderusing2stack(Node* root){
    //     stack<Node*> st;
    //     vector<int>ans;
    //     stack<Node*> sttwo;
    //     st.push(root);
    //     while(!st.empty()){
    //       Node* ele = st.top();
    //       st.pop();
    //       sttwo.push(ele);
    //       if(ele->left!=NULL){
    //         st.push(ele->left);
    //       }
    //       if(ele->right!=NULL){
    //         st.push(ele->right);
    //       }
    //     }
    //     while(!sttwo.empty()){
    //         ans.push_back(sttwo.top()->val);
    //         sttwo.pop();
    //     }
    //     return ans;
    // }
    public:
    vector<vector<int> >levelorder(Node* root){
        vector<vector<int>>ans;
        queue<Node*> st;
        st.push(root);
        while(!st.empty()){
            int n = st.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                Node* ele = st.front();
                st.pop();
                temp.push_back(ele->val);
                if(ele->left!=NULL){
                    st.push(ele->left);
                }

                if(ele->right!=NULL){
                    st.push(ele->right);

                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

void print(vector<vector<int>>&v){
    for(auto num : v){
        for(int j : num)
        cout<<j<<" ";

        cout<<endl;
    }
    
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    Solution sol;
    vector<vector<int>>ans = sol.levelorder(root);
    print(ans);

}
