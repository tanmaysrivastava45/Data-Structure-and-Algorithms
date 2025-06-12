#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()) return 0; // edge case

        s.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if (word == endWord) return level;

            for (int i = 0; i < word.size(); i++) {
                string original = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (s.find(word) != s.end()) {
                        q.push({word, level + 1});
                        s.erase(word);
                    }
                }
                word = original;
            }
        }

        return 0;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
