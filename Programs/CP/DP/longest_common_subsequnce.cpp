#include <bits/stdc++.h>
using namespace std;
int LCS(string X,string Y)
{
   int n=X.size(),m=Y.size();
   int len_lcs[n+1][m+1];
   for(int i=0;i<=n;i++)
       len_lcs[i][0]=0;
   for(int i=0;i<=m;i++)
       len_lcs[0][i]=0;
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
     {
        if(X[i-1]==Y[j-1])
              len_lcs[i][j]=1+len_lcs[i-1][j-1];
        else
            len_lcs[i][j]=max(len_lcs[i-1][j],len_lcs[i][j-1]);
     }
   }
   return len_lcs[n][m];
}
int main()
{
    string s1,s2;
    cout<<"Enter two strings:\n";
    cin>>s1>>s2;
    int res=LCS(s1,s2);
    cout<<"Length of LCS is "<<res<<"\n";
    return 0;
}
