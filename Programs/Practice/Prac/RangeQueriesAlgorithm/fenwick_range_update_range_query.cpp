#include <bits/stdc++.h>
using  namespace std;
int arr[1000001];
int bit1[1000001],bit2[10000001];
int n;
void add(int bit[],int idx,int val)
{
    while(idx<=n)
      {
          bit[idx]+=val;
          idx+=idx&-idx;
      }
}
void range_add(int l,int r,int val)
{
    add(bit1,l,val);
    add(bit1,r+1,-val);
    add(bit2,l,val*(l-1));
    add(bit2,r+1,-val*r);
}
int sum(int bit[],int r)
{
    int res=0;
    while(r>0)
      {
          res+=bit[r];
          r-=r&-r;
      }
    return res;
}
int prefix_sum(int idx)
{
   return sum(bit1,idx)*idx-sum(bit2,idx);
}
int range_sum(int l,int r)
{
    return prefix_sum(r)-prefix_sum(l-1);
}
// void buildTree()
// {
//     for(int i=1;i<=n;i++)
//        {
//            add(bit1,i,arr[i]);
//            //add(bit2,i,arr[i]);
//        }
// }
int main()
{
   cin>>n;
  for(int i=1;i<=n;i++)
      cin>>arr[i];
    for(int i=1;i<=n;i++)
      {
          bit1[i]=0;
          bit2[i]=0;
      }
  int f[n+1]={0};
  f[0]=0;
  for(int i=1;i<=n;i++)
     f[i]=f[i-1]+arr[i];
  int q;
  cin>>q;
  while(q--)
   {
       int x;
       cin>>x;
       if(x==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<range_sum(l,r)+f[r]-f[l-1]<<"\n";
        }
       else
       {
           int l,r,val;
           cin>>l>>r>>val;
           range_add(l,r,val);
       }
       
   }
   return 0;

}