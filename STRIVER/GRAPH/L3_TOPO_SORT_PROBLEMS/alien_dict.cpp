#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_set<char> uniqueChars;
        for (const string& word : words) {
            for (char ch : word) {
                uniqueChars.insert(ch);
            }
        }

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize indegree for all unique characters
        for (char ch : uniqueChars) {
            indegree[ch] = 0;
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }
            // Check for invalid prefix case
            if (!found && w1.length() > w2.length())
                return "";
        }

        // Topological sort using Kahn's algorithm
        queue<char> q;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0)
                q.push(it->first);
        }

        string ans = "";
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            ans += ch;
            for (char neighbor : adj[ch]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Check for cycle
        if (ans.size() != uniqueChars.size())
            return "";

        return ans;
    }
};

int main() {
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    
    Solution sol;
    string order = sol.findOrder(words);

    if (order != "")
        cout << "Alien Dictionary Order: " << order << endl;
    else
        cout << "Invalid input (cycle or prefix error)" << endl;

    return 0;
}
