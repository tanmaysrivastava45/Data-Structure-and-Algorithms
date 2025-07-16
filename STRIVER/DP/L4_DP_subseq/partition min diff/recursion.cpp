#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if a subset with given target exists
bool subsetSumUtil(int ind, int target, vector<int>& arr) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    bool notTaken = subsetSumUtil(ind - 1, target, arr);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr);

    return notTaken || taken;
}

// Recursive version of the minimum subset sum difference
int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    int mini = INT_MAX;

    // Check all subset sums from 0 to totSum
    for (int s1 = 0; s1 <= totSum; s1++) {
        if (subsetSumUtil(n - 1, s1, arr)) {
            int s2 = totSum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n) << endl;

    return 0;
}
