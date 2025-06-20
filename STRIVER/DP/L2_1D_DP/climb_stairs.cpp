#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
           int sum = prev + prev2;
           prev2 = prev;
           prev = sum;
        }
        return prev;
    }
};

int main(){
    int n = 45;
    Solution obj;
    cout<<obj.climbStairs(n)<<endl;
}