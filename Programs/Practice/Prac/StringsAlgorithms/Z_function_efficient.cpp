/*
1. i>r -- the current position is outside of what we have already 
processed.

We will then compute z[i] with the trivial algorithm (that is, just
comparing values one by one). Note that in the end, if z[i]>0, we'll
have to update the indices of the rightmost segment, because it's 
guaranteed that the new r=i+z[i]−1 is better than the previous r.

2. i≤r -- the current position is inside the current segment match [l,r].
 
z[i]=min(r−i+1,z[i−l])

Time Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s)
{
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
                  l=i;
                  r=i+Z[i]-1;
              }
      }
      return Z;
}
int main()
{
    string s;
    cin>>s;
    vector<int> v=z_function(s);
    for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
    return 0;
}