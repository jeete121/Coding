#include <bits/stdc++.h>
using namespace std;


vector<string> commonChars(vector<string>& s) 
{
      int n=s.size();
        int f[n][26];
        for(int i=0;i<n;i++)
              for(int j=0;j<26;j++)
                     f[i][j]=0;
        for(int i= 0;i<n;i++)
          {
            string x=s[i];
            for(int j=0;j<x.size();j++)
                f[i][x[j]-'a']++;       
          }
        vector<string> res;
        for(int j=0;j<26;j++)
        {
            char c;
            int min1=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(f[i][j]<min1)
                {
                    min1=f[i][j];
                    c='a'+j;
                }
            
            }
          if(min1!=0)
          {
              string s1(1, c);
             while(min1--)
                   {
                 res.push_back(s1);
                     }
          }
        }
        return res;
}
int main()
{
   vector<string> s={"bella","label","roller"};
   vector<string> common=commonChars(s);
   for(int i=0;i<common.size();i++)
        cout<<common[i]<<" ";
   return 0;
}


