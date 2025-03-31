#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>words;
        string word;
        for(size_t i=0;i<n;i++)// unsigned integer i
        {
            if(s[i]==' ')
            {
                continue;//ignore the spaces 
            }
             word.clear(); //clears the contents of the word string. This ensures that word starts empty before beginning to collect new characters.
             while(i<n && s[i]!=' ')
               {
                  word=word+s[i];//Adds the current character (s[i]) to the word string.
                  i++;
               }
             words.push_back(word);//adds the completed word with words vector
        }
        reverse(words.begin(),words.end());
        string result;
        for(size_t i=0;i<words.size();i++)
        {
            if(i>0)
            {
                result=result+' ';
            }
            result=result+words[i];
        }
        return result;
       
    }
};
int main()
{
    Solution obj;
    cout<<obj.reverseWords("the sky is blue");
}