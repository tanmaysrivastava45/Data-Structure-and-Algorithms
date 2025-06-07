#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

// Helper function to create the test tree
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    TreeNode* p = root->left;           // Node with val = 2
    TreeNode* q = root->left->right;    // Node with val = 4

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}
