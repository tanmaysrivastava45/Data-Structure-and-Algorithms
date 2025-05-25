#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        if (!root) return {{}, {}, {}};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> preorder, inorder, postorder;

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                preorder.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            } else if (it.second == 2) {
                inorder.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            } else {
                postorder.push_back(it.first->data);
            }
        }

        return {preorder, inorder, postorder};
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec, const string& name) {
    cout << name << ": ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> traversals = sol.treeTraversal(root);

    printVector(traversals[0], "Preorder");
    printVector(traversals[1], "Inorder");
    printVector(traversals[2], "Postorder");

    return 0;
}
