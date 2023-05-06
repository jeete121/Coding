#include <bits/stdc++.h>
using namespace std;
int LCS(string X,string Y,string Z)
{
   int n=X.size(),m=Y.size(),o=Z.size();
   int len_lcs[n+1][m+1][o+1];
   memset(len_lcs,0,sizeof(len_lcs));
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
     {
      for(int k=1;k<=o;k++)
      {
        if(X[i-1]==Y[j-1]&&Y[j-1]==Z[k-1])
              len_lcs[i][j][k]=1+len_lcs[i-1][j-1][k-1];
        else
            len_lcs[i][j][k]=max(len_lcs[i-1][j][k],max(len_lcs[i][j-1][k],len_lcs[i][j][k-1]));
      }
     }
   }
   return len_lcs[n][m][o];
}
int main()
{
    string s1,s2,s3;
    cout<<"Enter three strings:\n";
    cin>>s1>>s2>>s3;
    int res=LCS(s1,s2,s3);
    cout<<"Length of LCS is "<<res<<"\n";
    return 0;
}

