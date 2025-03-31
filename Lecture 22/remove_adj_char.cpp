#include<iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
         int i=1;
       while(i<s.length()) 
       {
           if(s[i-1]==s[i])
           {
               s.erase(i-1,1);
               if(i>1)  /// to recheck whether there is any duplicate character
               {
                   i--;
               }
           }
           else{
               i++;
           }
      
       }
        
        return s;
            
    }
};
int main()
{
    string s;
    cin>>s;
    Solution obj;
   cout<< obj.removeDuplicates(s);
}