#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100001];
int in[1000001];
vector<int> ans;

//function for topological sort
bool kahn(int n)
{
        queue<int> q;
        for(int i=0;i<n;i++)
          if(in[i]==0)
                q.push(i);
      while(!q.empty())
      {
          int curr=q.front();
          ans.push_back(curr);
          q.pop();
          for(int child:arr[curr])
          {
              in[child]--;
              if(in[child]==0)
                    q.push(child);
          }
      }
      if(ans.size()==n)
            return true;
        return false;
}

//function to find the order in 
//which courses will done
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
              
        for(int i=0;i<numCourses;i++)
        {
            arr[i].clear();
            in[i]=0;
        }
        ans.clear();
        for(int i=0;i<prerequisites.size();i++)
         {
           int a=prerequisites[i][0];
           int b=prerequisites[i][1];
            arr[b].push_back(a);
            in[a]++;
         }
        if(kahn(numCourses))
            return ans;
        else
             return {};
} 
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites ={{1,0}};
    vector<int> order=findOrder(numCourses,prerequisites);
    for(int i=0;i<order.size();i++)
       cout<<order[i]<<" ";
    return 0;
}

