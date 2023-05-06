#include <bits/stdc++.h>
using namespace std;
int change(int x,vector<int> coins)
{
   if(x==0)
      return 0;
   int min1=INT_MAX;
   for(int coin:coins)
       {
         if(x-coin>=0)
           {
              int c=change(x-coin,coins);
              if(min1>c+1)
                min1=c+1;
           }
       }
      return min1;
}
int main()
{
   int n,p;
   cin>>n;
   vector<int> coins;
   for(int i=0;i<n;i++)
      {
         cin>>p;
         coins.push_back(p);
      }
  int x;
  cin>>x;
  int min1=change(x,coins);
  if(min1==INT_MAX)
     cout<<0<<"\n";
  else
     cout<<min1<<"\n";
  return 0; 
}