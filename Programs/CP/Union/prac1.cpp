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
        // long long max1=long long_MIN;
         for(long long i=0;i<n;i++)
            {
                cin>>arr[i];
               // max1=max(max1,arr[i]);
            }
         long long ans=0;
         //long long d=log2(max1)+1;
        // set<pair<long long,long long>> st;
         for(long long i=31;i>=0;i--)
            {
                long long cnt=0;
               // vector<long long> v;
                for(long long j=0;j<n;j++)
                  {
                      //cout<<(1<<i)<<"\n";
                      if(arr[j]>=(1<<i)&&arr[j]<(1<<(i+1)))
                         {
                           cnt++;
                            // v.push_back(j);
                         }
                  }
             ans+=cnt*(cnt-1)/2;
            }
         cout<<ans<<"\n";
     }
}