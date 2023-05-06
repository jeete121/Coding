#include <bits/stdc++.h>
using namespace  std;
int BLK;
int arr[100001];
int F[100001];
int MIN1(int x,int y)
{
    int res=INT_MAX;
    for(int i=x;i<=y;i++)
      res=min(res,arr[i]);
    return res;
}
int getMin(int l,int r)
{
   int LB=l/BLK;
   int LR=r/BLK;
   int res=INT_MAX;
   if(LB==LR)
     for(int i=l;i<=r;i++)
       res=min(arr[i],res);
    else
    {
     for(int i=l;i<(LB+1)*BLK;i++)
       res=min(res,arr[i]);
     for(int i=LB+1;i<LR;i++)
       res=min(res,F[i]);
    for(int i=LR*BLK;i<=r;i++)
      res=min(res,arr[i]);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int q,a,b;
    cin>>q;
    int x;
    while(q--)
     {
         cin>>a>>b;
         BLK=sqrt(n);
         for(int i=0;i<n/BLK;i++)
             F[i]=MIN1(i*BLK,(i+1)*BLK-1);
        if(n%BLK!=0)
                F[n/BLK]=MIN1((n/BLK)*BLK,n-1);
        //for(int i=0;i<=n/BLK;i++)
         // cout<<F[i]<<" ";
        //  cout<<endl;
         cout<<getMin(a,b)<<"\n";   
     }
}