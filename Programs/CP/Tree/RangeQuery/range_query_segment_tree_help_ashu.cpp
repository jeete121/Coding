/*
Query 0:convert x to i
Query 1:return count of even  from l to r
Query 2:return count of odd from l to r
*/
#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int st[400008];
void build(int node,int start,int end)
{
    if(start==end)
      {
        st[node]=arr[start];  
        return ;
      }
    else
    {
       int mid=(start+end)/2;
       build(2*node,start,mid);
       build(2*node+1,mid+1,end);
       st[node]=st[node*2]+st[node*2+1];
    }
}
void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
      {
          st[node]=st[node]-arr[idx]+val;
          arr[idx]=val;
      }
      else
      {
         int mid=(start+end)/2;
         if(start<=idx&&idx<=mid)
           update(node*2,start,mid,idx,val);
         else
          update(node*2+1,mid+1,end,idx,val);
         st[node]=st[node*2]+st[node*2+1]; 
      }
      
}
int query(int node,int start,int end,int l,int r)
{
    if(r<start||end<l)
      return 0;
    if(l<=start&&end<=r)
       return st[node];
    int mid=(start+end)/2;
    int p1=query(node*2,start,mid,l,r);
    int p2=query(node*2+1,mid+1,end,l,r);
    return p1+p2;
}
int main()
{
  int n,g,a,x,y,q;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>g;
    if(g&1)
      arr[i]=0;
    else
     arr[i]=1;
  }
  build(1,1,n);
  cin>>q;
  while(q--)
  {
    cin>>a;
    if(a==1)
    {
      cin>>x>>y;
      cout<<query(1,1,n,x,y)<<"\n";
    }
    else if(a==0)
    {
      cin>>x>>y;
      if(y%2==0)
         update(1,1,n,x,1);
      else
         update(1,1,n,x,0);
    }
    else
    {
      cin>>x>>y;
      cout<<y-x+(y!=x?1:0)-query(1,1,n,x,y)<<"\n";
    }
  }
  return 0;
}