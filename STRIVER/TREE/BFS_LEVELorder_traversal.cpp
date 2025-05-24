#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int>>level_order_traversal(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    if(root == NULL)return ans;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
           Node* node = q.front();
           q.pop();
           if(node->left != NULL)q.push(node->left);
           if(node->right != NULL)q.push(node->right);
           level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root ->right = new Node(3);
    root->left->left = new Node(8);
    root ->left->right = new Node(2);


    vector<vector<int>>ans = level_order_traversal(root);
    
    cout<<"THE LEVEL ORDER TRAVERSAL OF THE BINARY TREE IS: "<<endl;
    for(int i =0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}