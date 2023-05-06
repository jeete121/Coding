#include <bits/stdc++.h>
#define MAX 20
using namespace std;
int lookup[MAX][MAX];
vector<string> LCS(string X,string Y,int m,int n)
{
    if(m==0||n==0)
      {
          vector<string> v(1);
          return v;
      }
     if(X[m-1]==Y[n-1])
       {
           vector<string> lcs=LCS(X,Y,m-1,n-1);
           for(string &str:lcs)
              str.push_back(X[m-1]);
            return lcs;
       }
    if(lookup[m-1][n]>lookup[m][n-1]) 
       return LCS(X,Y,m-1,n);
    if(lookup[m][n-1]>lookup[m-1][n])
      return LCS(X,Y,m,n-1);
    vector<string> top=LCS(X,Y,m,n-1);
    vector<string> left=LCS(X,Y,m-1,n);
    top.insert(top.end(),left.begin(),left.end());
    return top;
}
void LCSLength(string X,string Y,int m,int n)
{
  for(int i=0;i<=m;i++)
    {
      for(int j=0;j<=n;j++)
         {
           if(i==0||j==0)
             lookup[i][j]=0;
           else if(X[i-1]==Y[j-1])
             lookup[i][j]=lookup[i-1][j-1]+1;
          else
            lookup[i][j]=max(lookup[i-1][j],lookup[i][j-1]);
         }
    }
}
set<string> LCS(string X,string Y)
{
   int m=X.size(),n=Y.size();
   LCSLength(X,Y,m,n);
   vector<string> v=LCS(X,Y,m,n);
   set<string> res(v.begin(),v.end());
   return res;
}
int main()
{
    string s1,s2;
    cout<<"Enter two strings:\n";
    cin>>s1>>s2;
    set<string> res=LCS(s1,s2);
    for(string str:res)
    cout<<str<<"\n";
    return 0;
}