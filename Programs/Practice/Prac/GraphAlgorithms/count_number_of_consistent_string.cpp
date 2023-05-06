#include <bits/stdc++.h>
using namespace std;

//function to count the consistent strings

int countConsistentStrings(string allowed, 
        vector<string>& words) 
{
        int cnt=0;
        set<char> st;
        for(int i=0;i<allowed.size();i++)
               st.insert(allowed[i]);
        for(int i=0;i<words.size();i++)
        {
            int flag=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(st.find(words[i][j])==st.end())
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                  cnt++;
        }
        return cnt;
    }
int main()
{
   string allowed="ab";
   vector<string> words={"ad","bd","aaab","baa","badab"};
   int  count=countConsistentStrings(allowed,words);
   cout<<count<<"\n";
   return 0;
}
