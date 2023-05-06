#include <bits/stdc++.h>
using namespace std;
long long int arr[1000001];
#define MAXN 1000001
#define K 25
long long int st[MAXN][K+1];
void init(long long int n)
{
    for(long long int i=0;i<n;i++)
        st[i][0]=arr[i];
    for(long long int j=1;j<=K;j++)
       {
           for(long long int i=0;i+(1<<j)<=n;i++)  
               st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
       }
}
long long int query(long long int l,long long int r)
{
    long long int sum=0;
    for(long long int j=K;j>=0;j--)
      {
          if((1<<j)<=r-l+1)
            {
                sum+=st[l][j];
                l+=1<<j;
            }
      }
    return sum;
}
int main()
{
 long long int n;
  long long int q;

 cin>>n;
  cin>>q;
 for(long long int i=0;i<n;i++)
    cin>>arr[i];
 init(n);

 while(q--)
  {
    long long int l,r;
    cin>>l>>r;
    l--;
    r--;
    cout<<query(l,r)<<"\n";
  }
 return 0;
}