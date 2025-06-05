#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// TreeNode Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                ans += "null,";
                continue;
            }

            ans += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }

        // Remove trailing "null"s
        while (ans.size() >= 5 && ans.substr(ans.size() - 5) == "null,") {
            ans.erase(ans.size() - 5);
        }

        if (!ans.empty() && ans.back() == ',') ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null" || data.empty()) return nullptr;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, str, ',')) break;
            if (str != "null") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            if (!getline(ss, str, ',')) break;
            if (str != "null") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Helper to print serialized string
void printSerialized(string data) {
    cout << "Serialized Tree: " << data << endl;
}

// Main function to test
int main() {
    // Construct the tree: [1,2,3,null,null,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    printSerialized(serialized);

    TreeNode* newRoot = codec.deserialize(serialized);
    string reserialized = codec.serialize(newRoot);
    printSerialized(reserialized);

    return 0;
}
