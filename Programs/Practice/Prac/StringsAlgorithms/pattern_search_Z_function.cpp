/*
Problem : Search the pattern in the text

To solve this problem, we create a new string s=p+⋄+t, that is, we apply 
string concatenation to p and t but we also put a separator character ⋄ 
in the middle (we'll choose ⋄ so that it will certainly not be present 
anywhere in the strings p or t

Compute the Z-function for s. Then, for any i in the interval 
[0;length(t)−1], we will consider the corresponding value 
k=z[i+length(p)+1]. If k is equal to length(p) then we know there
is one occurrence of p in the i-th position of t, otherwise there is 
no occurrence of p in the i-th position of t.

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> search_Z_function(string pat,string text)
{
    string s="";
    s+=pat;
    s+="#";
    s+=text;
    int n=s.size();
    vector<int> Z(n,0);
    for(int i=1,l=0,r=0;i<n;i++)
      {
         if(i<=r)
            Z[i]=min(r-i+1,Z[i-l]);
        while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]])
          Z[i]++;
        if(i+Z[i]-1>r)
          {
              r=i+Z[i]-1;
              l=i;
          }
      }
      vector<int> res;
    for(int i=0;i<text.size();i++)
      {
          int k=Z[i+pat.size()+1];
          if(k==pat.size())
              res.push_back(i);
      }
    return  res;
}
int main()
{
    string text,pat;
    cin>>text>>pat;
    vector<int> v=search_Z_function(pat,text);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0; 
}