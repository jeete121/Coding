#include <bits/stdc++.h>
using namespace std;
int change1(int x,vector<int> coins,int cache[])
{
   if(x==0)
      return 0;
   int min1=INT_MAX;
   for(int coin:coins)
       {
          if(x-coin>=0)
            {
               int c;
               if(cache[x-coin]>=0)
                  c=cache[x-coin];
               else
               {
                 c=change1(x-coin,coins,cache);
                 cache[x-coin]=c;
               }
              if(min1>c+1)
                 min1=c+1; 
            }
       }
      return min1;
}
int change(int x,vector<int> coins)
{
    int cache[x];
    for(int i=0;i<x;i++)
        cache[i]=-1;
   return change1(x,coins,cache);
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
     cout<<0<<" ";
  else
     cout<<min1<<"\n";
  return 0; 
}