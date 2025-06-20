#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
  int fibonacci(int n){
    if(n<=1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
  }
};


int main(){
    int n=7;
    Solution obj;
    cout<<obj.fibonacci(n)<<endl;
    // 0 1 1 2 3 5 8 13
}