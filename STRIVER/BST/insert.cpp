#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        bool is = true;
        TreeNode* node = root;

        if (root == nullptr) {
            TreeNode* newRoot = new TreeNode(val);  // Don't shadow `root`
            return newRoot;
        }

        while (is) {
            if (root->val < val && root->right != nullptr) {
                root = root->right;
            } else if (root->val < val && root->right == nullptr) {
                root->right = new TreeNode(val);
                is = false;
            } else if (root->val > val && root->left != nullptr) {
                root = root->left;
            } else {
                root->left = new TreeNode(val);
                is = false;
            }
        }
        return node;
    }
};

/* Utility function for inorder traversal */
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/* Main to test the insertIntoBST function */
int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Inserting values into BST
    root = sol.insertIntoBST(root, 5);
    root = sol.insertIntoBST(root, 3);
    root = sol.insertIntoBST(root, 7);
    root = sol.insertIntoBST(root, 2);
    root = sol.insertIntoBST(root, 4);
    root = sol.insertIntoBST(root, 6);
    root = sol.insertIntoBST(root, 8);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
