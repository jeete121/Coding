#include <bits/stdc++.h>
using namespace std;
int parent[10001];
void make_set(int v)
{
    for(int i=0;i<v;i++)
       parent[i]=i;
}
int find_set(int a)
{
    if(a==parent[a])
       return a;
    return find_set(parent[a]);
}
void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
      parent[b]=a;
}
int main()
{
  int n;
  cin>>n;
  make_set(n);
  union_sets(1,3);
  union_sets(0,5);
  union_sets(1,4);
  union_sets(1,2);
  if(find_set(1)!=find_set(2))
    cout<<"1 and 2 are not in same set\n";
  else
    cout<<"1 and 2 are in same set\n";
   return 0;
}
