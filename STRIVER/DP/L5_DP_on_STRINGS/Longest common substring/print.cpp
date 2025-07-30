#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(string& s1, string& s2, int i, int j, int count, int& maxLen, int& endIndex) {
    if (i == s1.size() || j == s2.size()) return;

    if (s1[i] == s2[j]) {
        solve(s1, s2, i + 1, j + 1, count + 1, maxLen, endIndex);
        if (count + 1 > maxLen) {
            maxLen = count + 1;
            endIndex = i;
        }
    }

    // restart count since substring must be continuous
    solve(s1, s2, i + 1, j, 0, maxLen, endIndex);
    solve(s1, s2, i, j + 1, 0, maxLen, endIndex);
}

string longestCommonSubstring(string s1, string s2) {
    int maxLen = 0;
    int endIndex = -1;

    solve(s1, s2, 0, 0, 0, maxLen, endIndex);

    if (maxLen == 0) return "";
    return s1.substr(endIndex - maxLen + 1, maxLen);
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    string result = longestCommonSubstring(s1, s2);
    cout << "Longest Common Substring: " << result << endl;

    return 0;
}
