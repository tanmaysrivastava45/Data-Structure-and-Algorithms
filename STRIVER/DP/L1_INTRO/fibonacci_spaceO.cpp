#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int prev = 1;
    int prev2 = 0;
    for(int i=2;i<=n;i++){
        int sum = prev + prev2;
        prev2 = prev;
        prev = sum;
    }
    cout<<prev;
}