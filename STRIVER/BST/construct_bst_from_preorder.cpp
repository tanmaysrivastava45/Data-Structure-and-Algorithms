#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with the recursive BST builder
class Solution {
public:
    TreeNode* recursion(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = recursion(preorder, i, node->val);
        node->right = recursion(preorder, i, bound);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return recursion(preorder, i, INT_MAX);
    }
};

// Helper function to print inorder traversal (to verify correctness)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
