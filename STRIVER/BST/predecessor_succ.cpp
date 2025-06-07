#include <iostream>
#include <vector>
using namespace std;

// Definition for a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;

        Node* curr = root;

        // Find predecessor
        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Find successor
        curr = root;
        while (curr) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (!pre) pre = new Node(-1);
        if (!suc) suc = new Node(-1);

        return {pre, suc};
    }
};

// ---------- Sample BST and Test ---------
int main() {
    // Constructing BST
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int key = 10;
    Solution sol;
    vector<Node*> result = sol.findPreSuc(root, key);

    cout << "Predecessor: " << result[0]->data << endl;
    cout << "Successor: " << result[1]->data << endl;

    return 0;
}
