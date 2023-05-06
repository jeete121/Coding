#include <bits/stdc++.h>
using namespace std;

//find the different characters
//all string contains only 
//lower case alphabets
char findTheDifference(string s, string t) 
{
        int f[26]={0};
        for(int i=0;i<t.size();i++)
         {
           f[t[i]-'a']++;   
         }
        for(int i=0;i<s.size();i++)
               f[s[i]-'a']--;
        char ans;
        for(int i=0;i<26;i++)
              if(f[i]>0)
                  {
                  ans=i+'a';
                  break;
                  }
        return ans;
 }
int main()
{
    string s="abcd";
    string t="abcde";
    char ch=findTheDifference(s,t);
    cout<<ch<<"\n";
    return 0;
}
