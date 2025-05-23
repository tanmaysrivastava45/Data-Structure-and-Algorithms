#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void recursion(Node* root,vector<int>& ans){
    if(root == NULL)return ;
    // left
    recursion(root->left,ans);
    // root
    ans.push_back(root->data);
    // right
    recursion(root->right,ans);
}

vector<int> inorder(Node* root){
    vector<int>ans;
    recursion(root,ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    vector<int>res = inorder(root);
    
    cout<<"Inorder Traversal :"<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

}