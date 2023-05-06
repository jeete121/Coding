#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, 
   int src, int dst, int K) 
{
     unordered_map<int,vector<pair<int,int>>>ump;
     for(int i=0;i<flights.size();i++)
         ump[flights[i][0]].push_back({flights[i][1],flights[i][2]});
     queue<pair<int,int>> q;
     int res=INT_MAX;
     q.push({src,0});
     int step=0;

     //itearate till queue is not empty
     while(!q.empty())
         {
           int len=q.size();
           for(int i=0;i<len;i++)
             {
              auto t=q.front();
              q.pop();
              if(t.first==dst)
                    res=min(res,t.second);
              for(auto j=0;j<ump[t.first].size();j++)
               {
                 if(t.second+ump[t.first][j].second>res)
                       continue;
                 q.push({ump[t.first][j].first,ump[t.first][j].second+t.second});
                  
               }
             }
            if(step++ >K)
                  break;
         }
        if(res==INT_MAX)
              return -1;
        else
            return res;
}

int main()
{
   int  n = 3;
   vector<vector<int>> edges ={{0,1,100},{1,2,100},{0,2,500}};
   int src = 0, dst = 2, k = 1;
   cout<<findCheapestPrice(n,edges,src,dst,k);
   return 0;
}
 