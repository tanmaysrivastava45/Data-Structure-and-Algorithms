#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return Treebuild(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1, mp); 
    }

private:
    TreeNode* Treebuild(vector<int>& postorder, int poststart, int postend,
                        vector<int>& inorder, int instart, int inend,
                        map<int, int>& mp) {
        if (poststart > postend || instart > inend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        int numsleft = inroot - instart;

        root->left = Treebuild(postorder, poststart, poststart + numsleft - 1,
                               inorder, instart, inroot - 1, mp);

        root->right = Treebuild(postorder, poststart + numsleft, postend - 1,
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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = sol.buildTree(inorder, postorder);

    // Output the inorder traversal of the constructed tree
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
