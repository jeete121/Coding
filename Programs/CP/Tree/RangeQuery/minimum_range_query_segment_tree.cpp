#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int st[400004];
void buildTree(int si,int ss,int se)
{
    if(ss==se)
       {
         st[si]=arr[ss];
         return;
       }
    int mid=(ss+se)/2;
    buildTree(si*2,ss,mid);
    buildTree(si*2+1,mid+1,se);
    st[si]=min(st[2*si],st[si*2+1]);
}
int query(int si,int ss,int se,int qs,int qe)
{
    if(qs>se||qe<ss)
      return INT_MAX;
    if(ss>=qs&&se<=qe)
      return st[si];
    int mid=(ss+se)/2;
    int l=query(2*si,ss,mid,qs,qe);
    int r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    int q,l,r;
    cin>>q;
    buildTree(1,1,n);
    for(int i=0;i<q;i++)
    {
          cin>>l>>r;
          int res=query(1,1,n,l+1,r+1);
          cout<<res<<"\n";
      }

}