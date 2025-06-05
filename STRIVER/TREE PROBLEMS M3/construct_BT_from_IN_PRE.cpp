#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class with buildTree logic
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return Treebuild(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1, mp);
    }

private:
    TreeNode* Treebuild(vector<int>& preorder, int prestart, int preend,
                        vector<int>& inorder, int instart, int inend,
                        map<int, int>& mp) {
        if (prestart > preend || instart > inend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int numsleft = inroot - instart;

        root->left = Treebuild(preorder, prestart + 1, prestart + numsleft,
                               inorder, instart, inroot - 1, mp);

        root->right = Treebuild(preorder, prestart + numsleft + 1, preend,
                                inorder, inroot + 1, inend, mp);

        return root;
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    
    // Sample input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);

    // Output the inorder traversal of the constructed tree
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
