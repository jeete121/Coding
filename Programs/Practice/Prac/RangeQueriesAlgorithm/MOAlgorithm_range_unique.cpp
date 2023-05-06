#include <bits/stdc++.h>
using namespace std;
#define BLOCK 1000
struct  query
{
    int l;
    int r;
    int i;
};
query Q[1000001];
int ar[1000001],ans[10000001];
int freq[10000001];
int cnt=0;
bool cmp(query a,query b)
{
    if(a.l/BLOCK!=b.l/BLOCK)
        return a.l/BLOCK<b.l/BLOCK;
    return a.r<b.r;
}
void add(int pos)
{
    freq[ar[pos]]++;
    if(freq[ar[pos]]==1)
       cnt++;
}
void remove(int pos)
{
    freq[ar[pos]]--;
    if(freq[ar[pos]]==0)
       cnt--;
}
int main()
{
  int n,q;
  cin>>n;
  for(int i=0;i<n;i++)
      cin>>ar[i];
  cin>>q;
  for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
        Q[i].l--;
        Q[i].r--;
    }
  sort(Q,Q+q,cmp);
  int ML=0,MR=-1;
  for(int i=0;i<q;i++)
    {
        int L=Q[i].l;
        int R=Q[i].r;
        while(ML>L)
           {
               ML--;
               add(ML);
           }
         while(MR<R)
            {
                MR++;
                add(MR);
            }
         while(ML<L)
           {
               remove(ML);
               ML++;
           }
         while(MR>R)
           {
               remove(MR);
               MR--;
           }
           ans[Q[i].i]=cnt;
    }
    for(int i=0;i<q;i++)
       cout<<ans[i]<<"\n";
  return 0;
}