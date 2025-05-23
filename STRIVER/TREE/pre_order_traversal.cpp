#include<iostream>
#include<vector>
using namespace std;


// defining tree structure 
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


// the recursive function mainly responsible for preorder traversal 
void recursion(Node* root,vector<int>&res){
    if(root==NULL){
        return;
    }

    res.push_back(root->data);  // root 
    recursion(root->left,res);  // left
    recursion(root->right,res); // right
}


// funtion of preorder to call the recursive function and also to store the result
vector<int> preorder(Node* root){
    vector<int>res ;
    recursion(root,res);
    return res;
}


/// constructing tree and handling printing of tree
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = preorder(root);

    cout<<" the preorder traversal is : "<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}