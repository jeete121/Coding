/*
Find element in range L to R which are strictly smaller than;
query :L R K
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
vector<int> tree[4*MAXN];
int arr[MAXN];
void build(int node,int start,int end)
{
    if(start==end)
     {
         tree[node].push_back(arr[start]);
         return;
     }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    int i=0,j=0;
    while(i<tree[2*node].size()&&j<tree[2*node+1].size())
      {
          if(tree[2*node][i]<=tree[2*node+1][j])
            {
                tree[node].push_back(tree[2*node][i]);
                i++;
            }
            else
            {
                tree[node].push_back(tree[2*node+1][j]);
                j++;
            }
      }
      while(i<tree[2*node].size())
       {
           tree[node].push_back(tree[2*node][i]);
           i++;
       }
     while(j<tree[2*node+1].size())
       {
           tree[node].push_back(tree[2*node+1][j]);
           j++;
       }
}
int query(int node,int start,int end,int l,int r,int k)
{
    if(r<start||l>end)
      return 0;
    if(l<=start&&r>=end)
    {
        int res=upper_bound(tree[node].begin(),tree[node].end(),k-1)-tree[node].begin();
        return res;
    }
   int mid=(start+end)/2;
   int p1=query(2*node,start,mid,l,r,k);
   int p2=query(2*node+1,mid+1,end,l,r,k);
   return p1+p2;
}
int main()
{
  int n,q,l,r,k;
  cin>>n;
  for(int i=1;i<=n;i++)
     cin>>arr[i];
  build(1,1,n);
  cin>>q;
  while(q--)
    {
        cin>>l>>r>>k;
        cout<<query(1,1,n,l,r,k)<<"\n";
    }
  return 0;
}