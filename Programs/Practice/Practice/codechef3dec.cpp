#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
      int res=0;
        cin>>n;
        string s;
        cin>>s;
        int f[26]={0};
        for(int i=0;i<n;i++)
            f[s[i]-97]++;
        for(int i=0;i<26;i++)
              cout<<f[i]<<" ";
      cout<<"\n";
        for(int i=0;i<26;i++)
        {
			if(f[i]&1)
               res+=f[i]/2-1;
            else
              res+=f[i]/2;
		}
      cout<<res<<"\n";

    }
}
