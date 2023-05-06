#include <bits/stdc++.h>
using namespace std;


vector<int> visits;
vector<vector<pair<int, int>>> edgeMap;

//dfs funtion
void dfs(int id, int sum)
{
        if(sum < visits[id]) 
             visits[id] = sum;
        else
           return;
        
        for(pair<int, int> p : edgeMap[id])
                 dfs(p.first, sum + p.second);
}

int networkDelayTime(vector<vector<int>>& times, int N, int K)
{
        visits.resize(N+1, INT_MAX);
        edgeMap.resize(N+1);
        for(vector<int> v : times) 
            edgeMap[v[0]].push_back(make_pair(v[1], v[2]));
        
        dfs(K, 0);
        
        int res = 0;
        for(int i=1;i<=N;i++)
        {
            if(visits[i] == INT_MAX) 
                  return -1;
            res = max(visits[i], res);
        }
        return res; 
}
int main()
{
   vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
   int n = 4, k = 2;
   cout<<networkDelayTime(times,n,k);
   return 0;
}
