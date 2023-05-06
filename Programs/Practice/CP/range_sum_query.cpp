#include <bits/stdc++.h>
using namespace std;
long long st[10001][10001];
long long getRangeLtoR(int L,int R,int k)
{
   long long sum=0;
 for(int j=k;j>=0;j--)
    {
        if((1<<j)<=R-L+1)
          {
              sum+=st[L][j];
              L+=1<<j;
          }
    }
  return sum;
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
 for(int j=1;j<=k;j++)
   {
       for(int i=0;(i+(1<<j))<=n;i++)
            st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
   }
int L,R;
cin>>L>>R;
int sum=getRangeLtoR(L,R,k);
 cout<<sum<<"\n";
 cin>>L>>R;
 sum=getRangeLtoR(L,R,k);
 cout<<sum<<"\n";
 return 0;
}  