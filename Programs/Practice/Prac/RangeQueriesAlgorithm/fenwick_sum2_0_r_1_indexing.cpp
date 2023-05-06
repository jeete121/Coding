#include <bits/stdc++.h>
using namespace  std;
int bit[1001];
int arr[1001];
int n;
void add(int x, int delta)
{
      for(; x <= n; x += x&-x)
        bit[x] += delta;
}
int sum(int x)
{
     int sum1 = 0;
     for(; x > 0; x -= x&-x)
        sum1+= bit[x];
     return sum1;
}
void range_add(int l,int r,int val)
{
    add(l,val);
    add(r+1,-val);
}
 int main()
{
  //  ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
  //   cout.tie(NULL);
     int m,c;
     cin>>n>>m>>c;
    //  for(int i=1;i<=n;i++)
    //     arr[i]=c;
    //   buildTree();
     while(m--)
       {
           char x;
           cin>>x;
          if(x=='Q')
            {
                int l;
                cin>>l;
                cout<<sum(l)+c<<"\n";
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