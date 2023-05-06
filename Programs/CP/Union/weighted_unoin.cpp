#include <bits/stdc++.h>
using namespace std;
int root(int arr[],int i)
{
    while(arr[i]!=i)
      {
          arr[i]=arr[arr[i]];
          i=arr[i];
      }
    return i;
}
void initialize(int arr[],int size[],int n)
{
    for(int i=0;i<n;i++)
      {
          arr[i]=i;
          size[i]=1;
      }
}
void union1(int arr[],int size[],int a,int b)
{
    int root_a=root(arr,a);
    int root_b=root(arr,b);
    if(size[root_a]<size[root_b])
      {
          arr[root_a]=arr[root_b];
          size[root_b]+=size[root_a];
      }
    else
    {
       arr[root_b]=arr[root_a];
       size[root_a]+=size[root_b];
    }
    
}
bool find(int a,int b,int arr[])
{
    if(root(arr,a)==root(arr,b))
       return true;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n],size[n];
    initialize(arr,size,n);
    int k=n-1;
    for(int i=0;i<n;i++)
       {
           int x,y;
           cin>>x>>y;
           vector<int> v;
           if(!find(x,y,arr))
                {
                  union1(arr,size,x,y);
                  for(int i=0;i<n;i++)
                     v.push_back(size[i]);
                  sort(v.begin(),v.end());
                  for(int i=n-k;i<n;i++)
                     cout<<v[i]<<" ";
                 cout<<"\n"; 
                 k=k-1;
                }
             else
             {
            for(int i=0;i<n;i++)
                v.push_back(size[i]);
                sort(v.begin(),v.end());
              for(int i=n-k;i<n;i++)
                 cout<<v[i]<<" ";
                cout<<"\n";
             }
             
       }
}