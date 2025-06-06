#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BST search function
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

// In-order traversal for visual check
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            8
           / \
          3   10
         / \     \
        1   6     14
           / \   /
          4   7 13
    */

    // Manually constructing the BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    Solution sol;
    int val = 6;

    TreeNode* result = sol.searchBST(root, val);

    if (result != nullptr) {
        cout << "Node found with value: " << result->val << endl;
    } else {
        cout << "Node not found." << endl;
    }

    return 0;
}
