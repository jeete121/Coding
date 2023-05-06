#include <bits/stdc++.h>
using namespace std;


//function to find the unique 
//morse representation of all words
int uniqueMorseRepresentations(vector<string>& words) {
     map<char,string> mp;
     //unique morse code for each
     //character
    string arr[]={".-","-...","-.-.","-..",".",
             "..-.","--.","....","..",".---","-.-",
             ".-..","--","-.","---",".--.","--.-",
             ".-.","...","-","..-","...-",".--",
             "-..-","-.--","--.."}; 
     set<string> st;
      for(int i=0;i<26;i++)
              mp[i+'a']=arr[i];
        for(int i=0;i<words.size();i++)
        {
            string str="";
            for(int j=0;j<words[i].size();j++)
                   str+=mp[words[i][j]];
            st.insert(str);
        }
   return st.size();
 }
int main()
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    int unique=uniqueMorseRepresentations(words);
    cout<<unique<<"\n";
    return 0;
}

