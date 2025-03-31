// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int countDuplicates(int arr[], int n) {
//     unordered_map<int, int> freq;
//     int count = 0;

//     // Count the frequency of each element
//     for (int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//     }

//     // Count elements with frequency > 1
//     for (auto it : freq) {
//         if (it.second > 1) {
//             count++;
//         }
//     }

//     return count;
// }

// int main() {
//     int arr[] = {1, 2, 3, 2, 4, 5, 1, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     cout << "Count of duplicate elements: " << countDuplicates(arr, n) << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string lexicographicallyLargest(string s) {
    int n = s.size();
    vector<char> even, odd;

    // Separate even and odd indexed digits
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 2 == 0)
            even.push_back(s[i]);  // Even digits
        else
            odd.push_back(s[i]);   // Odd digits
    }

    // Sort both in descending order to maximize lexicographical order
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    // Place back sorted digits while maintaining parity positions
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 2 == 0)
            s[i] = even[evenIndex++];
        else
            s[i] = odd[oddIndex++];
    }

    return s;
}

int main() {
    string s = "6589314";
    cout << "Lexicographically Largest Number: " << lexicographicallyLargest(s) << endl;
    return 0;
}
