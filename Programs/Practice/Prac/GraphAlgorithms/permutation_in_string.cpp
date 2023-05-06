#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string p, string s) 
{
       int n=s.size(),m=p.size();
        if(n<m)
              return false;
        string x="";
        for(int i=0;i<m;i++)
              x+=s[i];
        int f[26]={0},f1[26]={0},flag=0;
        for(int i=0;i<m;i++)
              f[s[i]-'a']++;
        for(int i=0;i<m;i++)
               f1[p[i]-'a']++;
        for(int i=0;i<26;i++)
               if(f[i]!=f1[i])
               {
                     flag=1;
                     break;
               }
       if(flag==0)
              return true;
        for(int i=m;i<n;i++)
         {      
             flag=0;
             f[s[i]-'a']++;
             f[s[i-m]-'a']--;
             for(int i=0;i<26;i++)
             {
                 if(f[i]!=f1[i])
                 {
                     flag=1;
                     break;
                 }
             }
          if(flag==0)
                 return true;
         }
     return false;
}
int main()
{
    string s1 = "ab" ,s2 = "eidbaooo";
    if(checkInclusion(s1,s2))
       cout<<"true";
    else
      cout<<"false";
      return 0;
}
