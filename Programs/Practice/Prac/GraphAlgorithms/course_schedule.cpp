#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100001];
int in[100001];

//topoplogical sort function
bool kahn(int n)
{
        queue<int> q;
       for(int i=0;i<n;i++)
            if(in[i]==0)
                  q.push(i);
      int cnt=0;
       while(!q.empty())
       {
           int curr=q.front();
           cnt++;
           q.pop();
           for(int child:arr[curr])
           {
               in[child]--;
               if(in[child]==0)
                      q.push(child);
           }
       }
    if(cnt==n)
          return true;
    return false;
}

//function to check for course schedule
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
        for(int i=0;i<numCourses;i++)
        {
            arr[i].clear();
            in[i]=0;
        }
        for(int i=0;i<prerequisites.size();i++)
         {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            arr[a].push_back(b);
            in[b]++;
         }
        if(kahn(numCourses))
              return true;
        return false;
}
int main()
{
   int  numCourses = 2;
   vector<vector<int>> prerequisites ={{1,0},{0,1}};
   if(canFinish(numCourses,prerequisites))
     cout<<"true";
   else
     cout<<"false";
   return 0;
}
