#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // -----------------------------
    // map (Ordered)
    // -----------------------------
    map<string, int> orderedMap;

    // Insertion
    orderedMap["apple"] = 10;
    orderedMap.insert({"banana", 20});

    // Updation
    orderedMap["apple"] = 15;

    // Find
    auto it1 = orderedMap.find("apple");
    if (it1 != orderedMap.end()) {
        cout << "[map] Found 'apple' with value: " << it1->second << "\n";
    } else {
        cout << "[map] 'apple' not found\n";
    }

    // Deletion
    orderedMap.erase("banana");

    // Traversal
    cout << "\nOrdered Map (map):\n";
    for (auto &pair : orderedMap) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // -----------------------------
    // unordered_map (Unordered)
    // -----------------------------
    unordered_map<string, int> unorderedMap;

    // Insertion
    unorderedMap["carrot"] = 30;
    unorderedMap.insert({"date", 40});

    // Updation
    unorderedMap["carrot"] = 35;

    // Find
    auto it2 = unorderedMap.find("date");
    if (it2 != unorderedMap.end()) {
        cout << "\n[unordered_map] Found 'date' with value: " << it2->second << "\n";
    } else {
        cout << "\n[unordered_map] 'date' not found\n";
    }

    // Deletion
    unorderedMap.erase("date");

    // Traversal
    cout << "\nUnordered Map (unordered_map):\n";
    for (auto &pair : unorderedMap) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
