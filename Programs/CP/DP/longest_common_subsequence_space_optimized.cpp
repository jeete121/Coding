#include <bits/stdc++.h>
using namespace std;
int LCS(string X,string Y)
{
    int n=X.size(),m=Y.size();
    int curr[m+1],prev[m+1];
    for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                  curr[j]=0;
                else
                {
                  if(X[i-1]==Y[j-1])
                     curr[j]=prev[j-1]+1;
                else
                  curr[j]=max(prev[j],curr[j-1]);
                
                }
            }
         for(int i=0;i<=m;i++)
           prev[i]=curr[i];
      }
      return curr[m];
}
int main()
{
    string s1,s2;
    cout<<"Enter two strings:\n";
    cin>>s1>>s2;
    int res;
    if(s1.size()<s2.size())
        res=LCS(s2,s1);
    else
       res=LCS(s1,s2);
    cout<<"Length of LCS is "<<res<<"\n";
    return 0;
}