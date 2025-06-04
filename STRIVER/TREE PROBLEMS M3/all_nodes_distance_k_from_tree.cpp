/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left=NULL;
        right= NULL;
    }
};

class Solution {
public:
    void make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        make_parent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        int val = 0;
        TreeNode* node = target;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
          int n = q.size();
          if(val==k){
            break;
          }
          val++;
          for(int i=0;i<n;i++){
            TreeNode* curr =q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent[curr] && !visited[parent[curr]]){
                q.push(parent[curr]);
                visited[parent[curr]]=true;
            }
          }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};
int main() {
    // Example Tree:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;  // node 5
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
