//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // add code here.
        int n = q.size();
        stack<int>st;
         if (k > n || k <= 0) return q;  
       for(int i=0;i<k;i++){
           int val = q.front();
            q.pop();
            st.push(val);
        
        }
        while(!st.empty()){
            int val = st.top();
            st.pop();
            q.push(val);
        }
        int rem = n-k;
        for(int i = 0; i < rem; i++){
            int val = q.front();
             q.pop();
            q.push(val);
           
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.reverseFirstK(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends