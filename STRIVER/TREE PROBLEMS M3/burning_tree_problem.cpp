#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void make_parent(Node* root, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    Node* find_target_node(Node* root, int target) {
        if (root == NULL) return NULL;
        if (root->data == target) return root;
        Node* left = find_target_node(root->left, target);
        if (left) return left;
        return find_target_node(root->right, target);
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        make_parent(root, parent);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        Node* node = find_target_node(root, target);
        q.push(node);
        visited[node] = true;

        int time = 0;

        while (!q.empty()) {
            int n = q.size();
            bool anySpread = false;

            for (int i = 0; i < n; ++i) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    anySpread = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    anySpread = true;
                }
                if (parent.count(curr) && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                    anySpread = true;
                }
            }

            if (anySpread) time++;
        }

        return time-1;
    }
};

// --------- Helper to build tree from image input ---------
Node* build_test_tree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// ------------------- Main -------------------
int main() {
    Node* root = build_test_tree();
    int target = 2;

    Solution sol;
    int result = sol.minTime(root, target);

    cout << "Minimum time to burn the tree: " << result << " seconds" << endl;
    return 0;
}
