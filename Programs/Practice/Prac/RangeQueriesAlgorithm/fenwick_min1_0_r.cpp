#include <bits/stdc++.h>
using namespace std;
int arr[101];
int bit[101];
int n;
const int  INF=10000000;

//function to update the value
void update(int idx,int val)
{
 while(idx<n)
   {
       bit[idx]=min(bit[idx],val);
       idx=idx|(idx+1);
   }
}


//function to build the fenwick tree
void buildTree()
{
    for(int i=0;i<n;i++)
        update(i,arr[i]);
}

//function to find the minimum
//in range (0,r)
int getmin(int r)
{
  int res=INF;
  while(r>=0)
    {
        res=min(res,bit[r]);
        r=(r&(r+1))-1;
    }
    return res;
}
int main()
{ 
   n=5;
   arr[1]=3;
   arr[2]=1;
   arr[3]=4;
   arr[4]=2;
   arr[5]=5;
   for(int i=0;i<=n;i++)
      bit[i]=INF;
  buildTree();
  int r=3;
  cout<<getmin(r)<<"\n";
  return 0;
}