/// problem with this code is that overflow condition reaches since converting array to num makes it overflw condn


#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    long long value1 = 0;

    for (int i = 0; i < a.size(); i++) {
        value1 = value1 * 10 + a[i];
    }
    
    long long value2 = 0;
    for (int i = 0; i < b.size(); i++) {
        value2 = value2 * 10 + b[i];
    }
    
    long long sum = value1 + value2;
    
    cout<<sum<<endl;
}

int main() {
    vector<int> a = {1, 2, 3,7,8}; // represents 123
    vector<int> b = {4, 5, 6}; // represents 456
    int n = a.size();
    int m = b.size();
    
    findArraySum(a,n, b,m);
    
    return 0;
}