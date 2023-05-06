#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
int main()
{
    int n,m;
    cin>>n>>m;
    int dist[n][n];

    for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
             {
                 if(i!=j)
                    dist[i][j]=INF;
                 else
                   dist[i][j]=0;
             }
      }
    while(m--)
      {
          int a,b,w;
          cin>>a>>b>>w;
          a--;
          b--;
          dist[a][b]=w;
        // dist[b][a]=w;
      }
    for(int k=0;k<n;k++)
      {
          for(int i=0;i<n;i++)
            {
             // dist[i][i]=0;
                for(int j=0;j<n;j++)
                  {
                    if(dist[i][k]<INF &&dist[k][j]<INF)
                         dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                  }
            }
      }
  for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
             {
                 if(dist[i][j]==INF)
                    cout<<"INF ";
                 else
                    cout<<dist[i][j]<<" ";
                 
             }
         cout<<"\n";
     }
    return 0;
}