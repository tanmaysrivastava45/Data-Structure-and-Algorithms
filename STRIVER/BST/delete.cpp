#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Solution class with deleteNode method */
class Solution {
public:
    // Helper function to find the rightmost node of the left subtree
    TreeNode* findrightmost(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    // Helper function to delete a node and reattach subtrees properly
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        }
        if (root->right == nullptr) {
            return root->left;
        }

        TreeNode* rightside = root->right;
        TreeNode* leftside = findrightmost(root->left);
        leftside->right = rightside;
        return root->left;
    }

    // Main function to delete a node with given key
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* node = root;

        while (root) {
            if (key < root->val) {
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return node;
    }
};

/* Utility function to print Inorder traversal */
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/* Sample test */
int main() {
    /*
         5
        / \
       3   6
      / \   \
     2   4   7
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << "Original Inorder: ";
    inorder(root);
    cout << endl;

    int key = 3;
    root = sol.deleteNode(root, key);

    cout << "After deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
