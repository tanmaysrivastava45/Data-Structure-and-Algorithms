#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Flatten function using the iterative approach
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;  // Crucial step
            }
            curr = curr->right;
        }
    }
};

// Helper function to print the flattened tree (linked list)
void printFlattenedTree(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Driver code to test the function
int main() {
    /*
        Example Tree:
               1
              / \
             2   5
            / \   \
           3   4   6

        After flatten:
        1 - 2 - 3 - 4 - 5 - 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    printFlattenedTree(root);  // Output should be: 1 2 3 4 5 6

    return 0;
}
