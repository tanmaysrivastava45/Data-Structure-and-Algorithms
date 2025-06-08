#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Unified Iterator Class
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool isForward;

    BSTIterator(TreeNode* root, bool forward) : isForward(forward) {
        pushNodes(root);
    }

    void pushNodes(TreeNode* node) {
        while (node) {
            st.push(node);
            node = isForward ? node->left : node->right;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (isForward)
            pushNodes(node->right);
        else
            pushNodes(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// Main Solution
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, true);   // Forward iterator
        BSTIterator r(root, false);  // Reverse iterator

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

// Helper to insert a value in BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Main function for testing
int main() {
    vector<int> values = {5, 3, 6, 2, 4, 7}; // BST values
    int target = 9;

    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    Solution sol;
    if (sol.findTarget(root, target)) {
        cout << "Found a pair with sum " << target << endl;
    } else {
        cout << "No pair found with sum " << target << endl;
    }

    return 0;
}
