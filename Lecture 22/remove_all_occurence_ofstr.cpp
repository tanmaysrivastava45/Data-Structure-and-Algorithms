#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        // in this problem we use some inbuilt functions of string like erase and find 
        
      while(s.length()!=0 && s.find(part)<s.length())
      {
          
          // we will erase that part which is in the string and is a part of the string 
          
          s.erase(s.find(part),part.length());
      }
        return s;
    }
};
int main()
{
    string str;
    string part;
    cin>>str;
    cin>>part;
    Solution obj;
    cout<<obj.removeOccurrences(str,part);
}