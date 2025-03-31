#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    // 1. Insert Elements
    s.insert(50);
    s.insert(20);
    s.insert(30);
    s.insert(10);
    
    cout << "Set elements after insertion: ";
    for (int x : s) cout << x << " ";  
    cout << endl;  // Output: 10 20 30 50

    // 2. Check if an element exists
    if (s.count(20)) 
        cout << "20 is present in the set\n";
    else 
        cout << "20 is not present\n";

    // 3. Delete an element
    s.erase(20);
    cout << "Set after deleting 20: ";
    for (int x : s) cout << x << " ";  
    cout << endl;  // Output: 10 30 50

    // 4. Find an element
    auto it = s.find(30);
    if (it != s.end()) 
        cout << "30 is found in the set\n";
    else 
        cout << "30 is not found\n";

    // 5. Lower & Upper Bound
    cout << "Lower Bound of 25: " << *s.lower_bound(25) << "\n";  // First element >= 25 (Output: 30)
    cout << "Upper Bound of 30: " << *s.upper_bound(30) << "\n";  // First element > 30 (Output: 50)

    // 6. First and Last Element
    cout << "Minimum Element: " << *s.begin() << "\n";  // Output: 10
    cout << "Maximum Element: " << *s.rbegin() << "\n"; // Output: 50

    // 7. Set Size & Empty Check
    cout << "Size of Set: " << s.size() << "\n";
    cout << (s.empty() ? "Set is empty" : "Set is not empty") << "\n";

    // 8. Iterating Over a Set
    cout << "Elements using iterator: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 9. Reverse Iteration
    cout << "Elements in reverse order: ";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 10. Clear the Set
    s.clear();
    cout << "Set after clearing: " << (s.empty() ? "Empty" : "Not Empty") << "\n";

    return 0;
}
