#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> arr[10001];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,a,b,w;
    cin>>n>>m;
    while(m--)
      {
          cin>>a>>b>>w;
          arr[a].push_back({b,w});
          arr[b].push_back({a,w});  
      }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    int u,v;
    cin>>u>>v;
    pq.push({0,u});
    dist[u]=0;
    while (!pq.empty())
    {
        int curr=pq.top().second;
        int curr_d=pq.top().first;
        pq.pop();
        for(pair<int,int> edge:arr[curr])
         {
             if(curr_d+edge.second<dist[edge.first])
              {
                  dist[edge.first]=curr_d+edge.second;
                  pq.push({dist[edge.first],edge.first});
              }
         }
    }
    if(dist[v]==INT_MAX)
       cout<<"NO\n";
    else
        cout<<dist[v]<<"\n";
    
    }
    return 0;
    
}