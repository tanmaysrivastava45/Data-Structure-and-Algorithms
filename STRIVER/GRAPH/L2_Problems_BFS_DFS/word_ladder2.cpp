#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, 
                                       vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;

        vector<vector<string>> ans;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    s.erase(it);
                }
                usedOnLevel.clear(); // clear for the next level
            }

            string word = vec.back();
            if (word == endWord) {
                if (ans.empty()) {
                    ans.push_back(vec);
                } else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (s.find(word) != s.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    cout << "Shortest transformation sequences:\n";
    for (const auto& path : result) {
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
