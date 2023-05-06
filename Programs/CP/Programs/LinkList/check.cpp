#include <bits/stdc++.h>
using namespace std;
int st[10001][10001];
int Log[10001];
long long getRangeLtoRMin(int L,int R,int k,int Log[])
{
    int j=Log[R-L+1];
    int  minimum= min(st[L][j],st[R-(1<<j)+1][j]);
    return minimum;
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k=log2(n)+1;
  for(int i=0;i<n;i++)
     st[i][0]=arr[i];
  Log[1]=0;
  for(int i=2;i<=n;i++)
     Log[i]=Log[i/2]+1;
 for(int j=1;j<=k;j++)
   {
       for(int i=0;(i+(1<<j))<=n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
   }
 int q,L,R;
 cin>>q;
 while(q--)
  {
      cin>>L>>R;
      int res=getRangeLtoRMin(L,R,k,Log);
      cout<<res<<"\n";
  }
 return 0;
}  