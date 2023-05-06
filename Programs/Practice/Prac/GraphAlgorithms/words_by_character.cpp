#include <bits/stdc++.h>
using namespace std;


int countCharacters(vector<string>& words, string chars) 
{
     int n=words.size();
     int m=chars.size();
     int f[26]={0},f1[26]={0};
     for(int i=0;i<m;i++)
           f[chars[i]-'a']++;
     for(int i=0;i<26;i++)
           f1[i]=f[i];
    int res=0;
     for(int i=0;i<n;i++)
     {
         for(int i=0;i<26;i++)
               f[i]=f1[i];
         int j=0;
         string str=words[i];
         for(j=0;j<str.size();j++)
         {
             if(f[str[j]-'a'])
                   f[str[j]-'a']--;
             else
                 break;
              if(j==str.size()-1)
                 res+=str.size();
         }
     
     }
        return res;
}
int main()
{
    vector<string> words ={"cat","bt","hat","tree"};
    string chars = "atach";
    cout<<countCharacters(words,chars);
    return 0;
}
