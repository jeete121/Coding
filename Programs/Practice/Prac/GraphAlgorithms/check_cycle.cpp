#include <bits/stdc++.h>
using namespace std;

//adjacency list of the
//graph
vector<int> arr[100001];

//count the indegree of the node
int indegree[100001];

//function to add the edges 
//of the graph
void addEdge(int u,int v)
{
    //directed graph
    arr[u].push_back(v);
    //increment the indegree
    indegree[v]++;
}
//function to check the
//cycle in graph
bool isCycle(int n)
{
  //queue to store the nodes
   queue<int> q;
   
   //store the result
   vector<int> res;
   for(int i=1;i<=n;i++)
      {
         //if indegree of node is zero
         //push into to the queue
          if(indegree[i]==0)
             q.push(i);
      }
    while(!q.empty())
      {
          //get current node from
          //queue 
          int curr=q.front();
          //popped out the current node
          q.pop();
          //push the current node into the result
          res.push_back(curr);
          for(int child:arr[curr])
            {
              //decrement the indegree
              //of the node
               indegree[child]--;
            
              //if indegree becomes zero
              //push into the queue
               if(indegree[child]==0)
                  q.push(child);

                   
            }
      }
     //result contains same no
     //of elements as n then theie is no
     //cycle
      if(res.size()==n)
         return false;
    //else their is a cycle
     else
     {
         return true;
     }
     

}
int main()
{
    int n=6;
    int edges=6;
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,1);
    addEdge(6,2);
    addEdge(4,3);
    addEdge(5,3);
    if(isCycle(n))
       cout<<"Cycle is present\n";
    else
      cout<<"Cycle is not present\n";
   return 0;

}