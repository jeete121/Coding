#include <bits/stdc++.h>
using namespace std;
int tree[4000010];
int arr[1000001];
int gcd(int a,int b)
{
    if(b==0)
       return a;
    return gcd(b,a%b);
}
void build(int node,int start,int end)
{
    if(start==end)
     {
         tree[node]=arr[start];
         return ;
     }
     int mid=(start+end)/2;
     build(2*node,start,mid);
     build(2*node+1,mid+1,end);
     tree[node]=gcd(tree[2*node],tree[2*node+1]);
}
int query(int node,int start,int end,int l,int r)
{
    if(start>r||end<l)
       return 0;
    if(start>=l&&end<=r)
      return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return gcd(p1,p2);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
     {
         int l,r;
         cin>>l>>r;
         cout<<query(1,1,n,l,r)<<"\n";
     }
}