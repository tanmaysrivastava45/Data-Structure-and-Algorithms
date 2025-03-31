#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n == 1){
            cout << "NO\n";
            continue;
        }
        bool allSame = true;
        for (int i = 1; i < n; i++){
            if (s[i] != s[0]){
                allSame = false;
                break;
            }
        }
        if(allSame){
            cout << "NO\n";
            continue;
        }
        int minCost = INT_MAX;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i == j) continue;
                if(s[i] < s[j]){
                    int cost = 0;
                    cost += (i == 0) ? 0 : 1;
                    cost += (j == n - 1) ? 0 : 1;
                    if(i == n - 1 && j == 0)
                        cost = 1;
                    minCost = min(minCost, cost);
                }
            }
        }
        
        cout << (minCost <= k ? "YES" : "NO") << "\n";
    }
    return 0;
}
