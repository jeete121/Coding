#include <bits/stdc++.h>
using namespace std;

//function to count minimum
//deletions to make the frequency of
//each characters as unique
int minDeletions(string s) 
{
     int f[26]={0};
        for(int i=0;i<s.size();i++)
               f[s[i]-'a']++;
        int cnt=0;
        set<int> st;
        for(int i=0;i<26;i++)
        {
            if(f[i]>0)
             {
               if(st.find(f[i])!=st.end())
               {
                   cnt++;
                   int x=f[i]-1;
                   int len=st.size();
                   st.insert(x);
                   while(x>0&&st.size()==len)
                   {
                       
                       len=st.size();
                       x--;
                       st.insert(x);
                       
                       cnt++;
                   }
               }
              else
                  st.insert(f[i]);
             }
        }
      return cnt;
}
int main()
{
    string s = "aaabbbcc";
    cout<<minDeletions(s);
    return 0;
}

