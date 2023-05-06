#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int  main()
{
  int  n;
  cin>>n;
  vector< pair <int,int> > vp;
  int a,b;
  for(int i=0;i<n;i++)
   {
     cin>>a>>b;
     vp.push_back(make_pair(a,b));
   }
   sort(vp.begin(),vp.end(),sortbysec);
   cout<<vp[0].first<<" "<<vp[0].second<<"\n";
   int finish=vp[0].second;
   //cout<<finish<<"\n";
   //for(int i=0;i<n;i++)
     //  cout<<vp[i].first<<" "<<vp[i].second<<"\n";
   //cout<<endl;
   for(int i=1;i<n;i++)
   {
    if(vp[i].first>=finish)
    {
        cout<<vp[i].first<<" "<<vp[i].second<<"\n";
        finish=vp[i].second;
    }
   }
   return 0;
}
