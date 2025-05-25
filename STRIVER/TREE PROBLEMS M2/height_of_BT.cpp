/*
Call: maxDepth(1)
    ├── Call: maxDepth(2)
    │     ├── Call: maxDepth(4)
    │     │     ├── maxDepth(NULL) → 0
    │     │     ├── maxDepth(NULL) → 0
    │     │     → return 1 + max(0, 0) = 1
    │     ├── Call: maxDepth(5)
    │     │     ├── maxDepth(NULL) → 0
    │     │     ├── maxDepth(NULL) → 0
    │     │     → return 1 + max(0, 0) = 1
    │     → return 1 + max(1, 1) = 2
    ├── Call: maxDepth(3)
    │     ├── maxDepth(NULL) → 0
    │     ├── Call: maxDepth(6)
    │     │     ├── maxDepth(NULL) → 0
    │     │     ├── maxDepth(NULL) → 0
    │     │     → return 1 + max(0, 0) = 1
    │     → return 1 + max(0, 1) = 2
→ return 1 + max(2, 2) = 3
*/
#include <iostream>
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
    // ✅ Recursive DFS approach
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }

    /*
    // ✅ Iterative BFS approach (level-order traversal)
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int length = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            length++;
        }
        return length;
    }
    */
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, nullptr, new TreeNode(6));

    Solution sol;
    cout << "Max Depth: " << sol.maxDepth(root) << endl;

    return 0;
}
