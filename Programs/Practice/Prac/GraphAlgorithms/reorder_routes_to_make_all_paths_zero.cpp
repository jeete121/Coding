#include <bits/stdc++.h>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections) 
{
    vector<vector<int>> arr(n),tr(n);
    vector<int> vis(n);

    //create the transpose graph
    //and graph
      for(int i=0;i<connections.size();i++)
        {
          int a=connections[i][0];
          int b=connections[i][1];
          arr[a].push_back(b);
          tr[b].push_back(a);
       }
      queue<int> q;
        q.push(0);
        int res=0;

        //iterate till the queue is not
        //empty
      while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(int child:arr[curr])
            {
                if(vis[child]==0)
                {
                    res++;
                    q.push(child);
                }
            }
        for(int child:tr[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
            }
        }
        }
        return res;
}

int main()
{
    int  n = 5;
    vector<vector<int>>  connections ={{1,0},{1,2},{3,2},{3,4}};
    cout<<minReorder(n,connections);
    return 0;
}