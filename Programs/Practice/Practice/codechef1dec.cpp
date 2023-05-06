#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t,n;
 cin>>t;
 while(t--)
 {
    cin>>n;
    int p[n],s[n];
    for(int i=0;i<n;i++)
         cin>>p[i]>>s[i];
    int max1[9]={0};
    for(int i=0;i<n;i++)
    {
        if(p[i]<=8)
        {
            max1[p[i]]=max(max1[p[i]],s[i]);
        }
    }
    int res=0;
    for(int i=1;i<=8;i++)
         res+=max1[i];
    cout<<res<<"\n";
 }
}
