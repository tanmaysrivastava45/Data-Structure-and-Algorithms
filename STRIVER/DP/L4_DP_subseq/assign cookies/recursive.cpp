#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int recursion(vector<int>& g, vector<int>& s,int i,int j){
        if(i>=g.size() || j>=s.size()){
             return 0;
        }

        if(g[i]<=s[j]){
            return 1 + recursion(g,s,i+1,j+1);
        }
        else
        return recursion(g,s,i,j+1);
    }    
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        return recursion(g,s,0,0);
    }
};
int main(){
    // Input: g = [1,2,3], s = [1,1]
    // Output: 1

    Solution obj;
    vector<int>g = {1,2,3};
    vector<int>s = {1,1};
    cout<<obj.findContentChildren(g,s)<<endl;

}