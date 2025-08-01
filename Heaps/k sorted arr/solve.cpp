#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 1: push first k+1 elements into the heap
        for (int i = 0; i <= k && i < n; i++) {
            pq.push(arr[i]);
        }

        int index = 0;

        // Step 2: push next element and pop min to the array
        for (int i = k + 1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }

        // Step 3: empty the heap
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};
