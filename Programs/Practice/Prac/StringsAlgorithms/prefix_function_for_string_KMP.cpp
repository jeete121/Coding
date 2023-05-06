/*
1 .We compute the prefix values π[i] in a loop by iterating from 
i=1 to i=n−1 (π[0] just gets assigned with 0).

2. To calculate the current value π[i] we set the variable j
denoting the length of the best suffix for i−1. Initially j=π[i−1].

3. Test if the suffix of length j+1 is also a prefix by comparing 
s[j] and s[i]. If they are equal then we assign π[i]=j+1, otherwise 
we reduce j to π[j−1] and repeat this step.

4. If we have reached the length j=0 and still don't have a match,
then we assign π[i]=0 and go to the next index i+1.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s)
{
  int n=s.size();
  vector<int> pi(n);
  pi[0]=0;
  for(int i=1;i<n;i++)
    {
      int j=pi[i-1];
      while(j>0&&s[i]!=s[j])
        j=pi[j-1];
      if(s[i]==s[j])
         j++;
      pi[i]=j;
    }
    return pi;
}
vector<int> search_substring(string pat,string text)
{
    int m=pat.size();
    int n=text.size();
    vector<int> pi=prefix_function(pat);
    vector<int> res;
    int i=0,j=0;
    while(i<n)
     {
         if(pat[j]==text[i])
           {
               i++;
               j++;
           }
          if(j==m)
             {
                 res.push_back(i-j);
                 j=pi[j-1];
             }
        else if(i<n&&pat[j]!=text[i])
          {
              if(j>0)
                 j=pi[j-1];
              else
                i++;
          }
     }
     return res;
}
int main()
{
  string text,pat;
  cin>>text>>pat;
  vector<int> v=search_substring(pat,text);
  for(int i=0;i<v.size();i++)
     cout<<v[i]<<" ";
  return 0;
}