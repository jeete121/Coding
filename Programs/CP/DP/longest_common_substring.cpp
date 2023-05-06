#include <bits/stdc++.h>
using namespace std;
string LCS(string X,string Y)
{
    int m=X.size(),n=Y.size();
    int maxlen=0,endIndex=m;
    int lookup[m+1][n+1];
    memset(lookup,0,sizeof(lookup));
    for(int i=1;i<=m;i++)
      {
          for(int j=1;j<=n;j++)
            {
               if(X[i-1]==Y[j-1])
                 {
                      lookup[i][j]=1+lookup[i-1][j-1];
                      if(lookup[i][j]>maxlen)
                       {
                           maxlen=lookup[i][j];
                           endIndex=i;
                       }
                
            }
      }
    }
      return X.substr(endIndex-maxlen,maxlen);
}
int main()
{
    string s1,s2;
    cout<<"Enter thwo strings:\n";
    cin>>s1>>s2;
    string res=LCS(s1,s2);
    cout<<"Longest Common Substring "<<res<<"\n";
    return 0;
}