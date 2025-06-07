#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isValidBST(TreeNode* root) {
        return checkforBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool checkforBST(TreeNode* root, long long mini, long long maxi) {
        if (root == NULL) return true;
        if (root->val <= mini || root->val >= maxi) return false;
        return checkforBST(root->left, mini, root->val) &&
               checkforBST(root->right, root->val, maxi);
    }
};

// Utility function to create a simple tree for testing
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    Solution sol;
    if (sol.isValidBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}
