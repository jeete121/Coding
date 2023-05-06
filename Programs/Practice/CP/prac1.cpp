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
    return parent[a]=find_set(parent[a]);
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
    int n,p;
    cin>>n>>p;
    int x,y;
    make_set(n);
    for(int i=0;i<p;i++)
     {
       cin>>x>>y;
       union_sets(x,y);
     }
    int arr[n];
    for(int i=0;i<n;i++)
     {
         arr[i]=parent[i];
    }
    sort(arr,arr+n);
    int res=1;
    for(int i=0;i<n-1;i++)
     {
        
        int cnt=1;
       while(arr[i]==arr[i+1])
       {
          cnt++;
           i++;
        }
    res=res*cnt;
     }
  cout<<res<<"\n";
}