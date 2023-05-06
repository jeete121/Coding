#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  if(m>12||n>31)
     cout<<"Impossible\n";
  else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(n>31))
     cout<<"Impossible\n";
  else if(m==2&&n>28)
     cout<<"Impossible\n";
  else if((m==2||m==6||m==9||m==11)&&(n>30) )
     cout<<"Impossible\n";
  else
  {
  map<int,int> mp;
  mp[1]=31;mp[2]=28;mp[3]=31;mp[4]=30;
  mp[5]=31;mp[6]=30;mp[7]=31;mp[8]=31;
  mp[9]=30;mp[10]=31;mp[11]=30;mp[12]=31;
  int ans=n;
  for(int i=1;i<m;i++)
     ans+=mp[i];
   cout<<ans%7+1<<"\n";
  }
  return 0;
}