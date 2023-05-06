#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long t,n;
  cin>>t;
  while(t--)
  {
      cin>>n;
      long long arr[n];
      for(long long i=0;i<n;i++)
          cin>>arr[i];
      int cnt0=0,cnt2=0;
      for(long long i=0;i<n;i++)
      {
          if(arr[i]==0)
             cnt0++;
          if(arr[i]==2)
            cnt2++;
      }
      long long res=0;
      res+=cnt0*(cnt0-1)/2+cnt2*(cnt2-1)/2;
      cout<<res<<"\n";
  }
}
