#include <bits/stdc++.h>
using namespace std;


int longestSubstring(string s, int k) 
{
       if(s.size()==0||k>s.size())
             return 0;
       int ans1=0;
       int j=0;
       map<char,int> mp;
        for(int i=0;i<s.size();i++)
               mp[s[i]]++;
       while(j<s.size()&&mp[s[j]]>=k)
              j++;
       if(j==s.size())
              return j;
       ans1=longestSubstring(s.substr(0,j),k);
       while(j<s.size()&&mp[s[j]]<k)
              j++;
        int ans2=0;
        if(j<s.size())
        {
            ans2=longestSubstring(s.substr(j),k);
            
        }
        else
              ans2=0;
        return max(ans1,ans2);
}

int main()
{
    string str="aaabb";
    int k=3;
    cout<<longestSubstring(str,k);
    return 0;
}