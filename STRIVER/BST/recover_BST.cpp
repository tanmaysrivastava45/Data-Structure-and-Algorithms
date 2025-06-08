#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

// Utility function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Sample usage
int main() {
    /*
        Constructed binary search tree:
            3
           / \
          1   4
             /
            2
        Here, nodes 2 and 3 are swapped.
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}
