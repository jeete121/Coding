#include <bits/stdc++.h>
using namespace std;
long long int tree[4000011];
long long int arr[1000001];
long long int lazy[4000011];
void build(long long int node,long long int start,long long int end)
{
  if(start==end)
   {
     tree[node]=arr[start];
     return;
   }
  long long int mid=(start+end)/2;
  build(2*node,start,mid);
  build(2*node+1,mid+1,end);
  tree[node]=tree[2*node]+tree[2*node+1];

}
void update(long long int node,long long int start,long long int end,long long int l,long long int r,long long int val)
{
  if(lazy[node]!=0)
    {
      long long int dx=lazy[node];
      lazy[node]=0;
      tree[node]+=dx*(end-start+1);
      if(start!=end)
          {
            lazy[2*node]+=dx;
            lazy[2*node+1]+=dx;
          }
    }
    if(start>end||start>r||end<l)
        return ;
    if(start>=l&&end<=r)
      {
        long long int dx=(end-start+1)*val;
        tree[node]+=dx;
        if(start!=end)
          {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
          
          }
            return;
      }
     long long int mid=(start+end)/2;
     update(2*node,start,mid,l,r,val);
     update(2*node+1,mid+1,end,l,r,val);
     tree[node]=tree[2*node]+tree[2*node+1];
}
long long int query(long long int node,long long int start,long long int end,long long int l,long long int r)
{
  if(lazy[node]!=0)
    {
      long long int dx=lazy[node];
      lazy[node]=0;
      tree[node]+=dx*(end-start+1);
      if(start!=end)
        {
          lazy[2*node]+=dx;
          lazy[2*node+1]+=dx;
        }

    }
  if(start>end||r<start||l>end)
     return 0;
  if(start>=l&&r>=end)
     return tree[node];
   long long int mid=(start+end)/2;
   long long int p1=query(2*node,start,mid,l,r);
   long long int p2=query(2*node+1,mid+1,end,l,r);
   return p1+p2;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n,q;
  cin>>n>>q;
  for(long long int i=1;i<=n;i++)
     cin>>arr[i];
  build(1,1,n);
  //cout<<q<<"\n";

  while(q--)
    {
      long long int x;
      cin>>x;
      if(x==1)
        {
          long long int l,r,u;
          cin>>l>>r>>u;
          update(1,1,n,l,r,u);
        }
       else
       {
         long long int l;
         cin>>l;
         cout<<query(1,1,n,l,l)<<"\n";
       }
       
    }
    return 0;
}