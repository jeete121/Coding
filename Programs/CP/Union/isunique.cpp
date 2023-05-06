/*
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures? 
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int f[52]={0};
    int flag=0;
    for(int i=0;i<s.size();i++)
      {
          if(f[s[i]]>0)
               {
                   flag=1;
                   break;
               }
          else
          {
            f[s[i]]=1;
          }
          
      }
    if(flag==0)
       cout<<"YES\n";
    else
    {
          cout<<"NO\n";
    }
    return 0;
    
}