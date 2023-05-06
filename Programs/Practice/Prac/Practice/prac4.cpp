#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
     {
         int a,b;
         cin>>a>>b;
         arr[a].push_back(b);
         arr[b].push_back(a);
     }
     vector<int> side(1000001,-1);
     bool is_bipartite=true;
     queue<int> q;
     for(int i=1;i<=n;i++)
       {
           if(side[i]==-1)
            {
                q.push(i);
                side[i]=0;
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();
                    for(int child:arr[curr])
                     {
                         if(side[child]==-1)
                           {
                               side[child]=side[curr]^1;
                               q.push(child);
                           }
                          else
                            is_bipartite&=side[child]!=side[curr];
                          
                     }
                }
            }
       }
     if(is_bipartite==true)
       {
           for(int i=1;i<=n;i++)
              cout<<side[i]+1<<" ";
            
       }
     else
     {
         cout<<"IMPOSSIBLE\n";
     }
     
     
}