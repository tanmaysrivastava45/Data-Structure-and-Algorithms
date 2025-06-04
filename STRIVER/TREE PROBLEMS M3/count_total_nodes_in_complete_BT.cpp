#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int computeLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int computeRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = computeLeftHeight(root);
        int rightHeight = computeRightHeight(root);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // 2^h - 1
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

// Helper function to build a complete binary tree from level-order input
TreeNode* buildCompleteTree(vector<int> values) {
    if (values.empty()) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < values.size()) {
            curr->left = new TreeNode(values[i++]);
            q.push(curr->left);
        }
        if (i < values.size()) {
            curr->right = new TreeNode(values[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

int main() {
    // Example: Complete binary tree with 7 nodes
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    vector<int> treeData = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildCompleteTree(treeData);

    Solution sol;
    cout << "Total Nodes: " << sol.countNodes(root) << endl; // Output: 7

    return 0;
}
