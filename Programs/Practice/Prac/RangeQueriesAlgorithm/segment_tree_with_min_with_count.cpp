#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
pair<int,int> tree[4000010];
pair<int,int> combine(pair<int,int> a,pair<int,int> b)
{
   if(a.first<b.first)
      return a;
   if(a.first>b.first)
      return b;
   return make_pair(a.first,a.second+b.second);
}
void build(int node,int start,int end)
{
   if(start==end)
     {
        tree[node]=make_pair(arr[start],1);
        return;
     }
   int mid=(start+end)/2;
   build(2*node,start,mid);
   build(2*node+1,mid+1,end);
   tree[node]=combine(tree[2*node],tree[2*node+1]);
}
pair<int,int> query(int node,int start,int end,int l,int r)
{
   if(start>r||end<l)
      return make_pair(INT_MAX,0);
   if(start>=l&&end<=r)
      return tree[node];
   int mid=(start+end)/2;
   pair<int,int> p1=query(2*node,start,mid,l,r);
   pair<int,int> p2=query(2*node+1,mid+1,end,l,r);
   return combine(p1,p2);
}
void update(int node,int start,int end,int index,int val)
{
   if(start==end)
     {
        tree[node]=make_pair(val,1);
       return ;
     }
     int mid=(start+end)/2;
     if(index<=mid)
        update(2*node,start,mid,index,val);
     else
       update(2*node+1,mid+1,end,index,val);
      tree[node]=combine(tree[2*node],tree[2*node+1]);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
     cin>>arr[i];
 build(1,1,n);
  for(int i=1;i<=m;i++)
   {
     int x;
      cin>>x;
     
      if(x==1)
           {
              int index,val;
              cin>>index>>val;
              //arr[index+1]=val;
              update(1,1,n,index+1,val);
           }
        else
           {
              int l,r;
              cin>>l>>r;
              pair<int,int> p=query(1,1,n,l+1,r);
              cout<<p.first<<" "<<p.second<<"\n";
           }
   }
   return 0;
}