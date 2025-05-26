#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with DFS method
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = dfs(root->left);
        if (left == -1) return -1;
        int right = dfs(root->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

// Helper to build tree from vector input (level-order)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= nodes.size()) break;

        // Right child
        if (nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    // -1 represents null
    vector<int> input = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    
    TreeNode* root = buildTree(input);
    Solution sol;

    if (sol.isBalanced(root)) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is NOT height-balanced." << endl;
    }

    return 0;
}
