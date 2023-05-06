#include <bits/stdc++.h>
using namespace std;
const int INF =1000000;
struct Edge
{
    int w=INF,to=-1;
    bool operator<(Edge const& other) const
     {
         return make_pair(w,to)<make_pair(other.w,other.to);
     }
};
vector<Edge> arr[100001];
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
     {
         int a,b,w;
         cin>>a>>b>>w;
         Edge e1,e2;
         e1.to=b;
         e1.w=w;
         e2.to=a;
         e2.w=w;
         arr[a].push_back(e1);
         arr[b].push_back(e2);
     }
     int total_weight=0;
     vector<Edge> min_e(n+1);
     min_e[1].w=0;
     set<Edge> q;
     q.insert({0,1});
     vector<bool> vis(n+1,false);
     for(int i=0;i<n;i++)
       {
           if(q.empty())
            {
              cout<<"No Mst\n";
              exit(0);
            }
          int v=q.begin()->to;
          vis[v]=true;
          total_weight+=q.begin()->w;
          q.erase(q.begin());
          if(min_e[v].to!=-1)
             cout<<v<<" "<<min_e[v].to<<"\n";
         for(Edge e:arr[v])
           {
               if(!vis[e.to]&&e.w<min_e[e.to].w)
                 {
                     q.erase({min_e[e.to].w,e.to});
                     min_e[e.to]={e.w,v};
                     q.insert({e.w,e.to});
                 }
           }
       }
       cout<<total_weight<<"\n";
}