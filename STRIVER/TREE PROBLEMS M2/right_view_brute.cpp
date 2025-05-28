#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            bool isFirst = true;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (isFirst) {
                    ans.push_back(node->val);  // First node seen from right at this level
                    isFirst = false;
                }

                if (node->right) q.push(node->right);  // Push right first
                if (node->left) q.push(node->left);
            }
        }

        return ans;
    }
};

// Sample test
int main() {
    // Creating the binary tree:
    //         1
    //        / \
    //       2   3
    //        \   \
    //         5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, nullptr, new TreeNode(5));
    root->right = new TreeNode(3, nullptr, new TreeNode(4));

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup (not strictly necessary for small test cases)
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
