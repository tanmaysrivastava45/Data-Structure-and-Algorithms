#include <iostream>
#include <stack>
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

class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushleft(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushleft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushleft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// Sample test
int main() {
    // Create BST
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Instantiate iterator
    BSTIterator* it = new BSTIterator(root);

    // Use iterator
    while (it->hasNext()) {
        cout << it->next() << " ";
    }

    // Clean up (not necessary for small example, but good practice)
    delete it;

    return 0;
}
