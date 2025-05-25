#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with inorderTraversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while (node != nullptr || !st.empty()) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};

// Helper function to print the result
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    /*
        Sample Binary Tree:
            1
             \
              2
             /
            3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    cout << "In-order Traversal: ";
    printVector(result);

    // Free allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
