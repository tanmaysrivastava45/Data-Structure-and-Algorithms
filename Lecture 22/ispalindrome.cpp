#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int b = 0;
    int e = s.size() - 1;

    while (b < e)
    {
        // Skip non-alphanumeric characters
        while (b < e && !isalnum(s[b])) {
            b++;
        }
        while (b < e && !isalnum(s[e])) {
            e--;
        }

        // Compare characters ignoring case
        if (tolower(s[b]) != tolower(s[e])) {
            return false;
        }

        b++;
        e--;
    }
    return true;
}

int main() {
    string s = "c1 O$d@eeD o1c";
    if (checkPalindrome(s))
        cout << "Yes, it's a palindrome" << endl;
    else
        cout << "No, it's not a palindrome" << endl;

    return 0;
}
