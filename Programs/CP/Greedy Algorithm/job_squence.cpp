#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}
int  main()
{
 int n;
 cin>>n;
 vector < pair <int,int> > vp;
 int a,b;
 for(int i=0;i<n;i++)
 {
  cin>>a>>b;
  vp.push_back(make_pair(a,b));
 }
 sort(vp.begin(),vp.end(),sortbysec);
 bool slot[n];
 for(int i=0;i<n;i++)
      slot[i]=false;
 vector< pair <int,int> > res;
// int max1=vp[0].first;
 for(int i=0;i<n;i++)
 {
    for(int j=min(n,vp[i].first);j>=1;j--)
    {
      if(slot[j]==false)
      {
          res.push_back(make_pair(j,vp[i].second));
          slot[j]=true;
          break;
      }
    }
 }
 sort(res.begin(),res.end());
 for(int i=0;i<res.size();i++)
      cout<<res[i].first<<" "<<res[i].second<<"\n";
}
