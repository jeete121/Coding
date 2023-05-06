#include <bits/stdc++.h>
using namespace std;

// adjacency list
vector<int> arr[1000001];


//function to add the edges into
//the graph
void addEdge(int u,int v)
{

    //undirected graph
    arr[u].push_back(v);
    arr[v].push_back(u);
}
//function to check the graph
//is bipartite or not
bool isBipartite(int n)
{

  //to hold the which side the
  //node comes
   vector<int> part(n+1,-1);

  //variable hold the bipartiteness
  //of the graph
   bool is_bipartite=true;

 //queue to hold the incomimg
 //nodes
   queue<int> q;
 //iterate for all nodes
   for(int i=1;i<=n;i++)
     {

        //if node is not partitioned
    if(part[i]==-1)
          {

      //push into the queue
         q.push(i);

        //assine side as 0
         part[i]=0;

       //iterate till the queue is not empty
       while(!q.empty())
            {
               int curr=q.front();
                  q.pop();

           //iterate for adjacency list
            //of the current node
            for(int child:arr[curr])
                     {
                  //if not partioned then
                  //partitioned opposide side
                 //of the current element
                 if(part[child]==-1)
                     {
                        part[child]=part[curr]^1;
                        q.push(child);
                      }
                //if already partitione then 
                //if both are are same side then bipartite 
                //will we false else bipartite as true
                //so update this as bipartite&=part[child]!=part[curr]
                  else
                    is_bipartite&=part[child]!=part[curr];
                          
                }
            }
         }
    }
    return is_bipartite;
   
}
int main()
{
  
  int n=6;
  addEdge(1,2);
  addEdge(1,3);
  addEdge(2,4);
  addEdge(3,5);
  addEdge(5,6); 
  //addEdge(1,5);   uncomment this line graph will be not bipartite
  if(isBipartite(n))
     cout<<"Graph is Bipartite\n";
  else
    cout<<"Graph is not Bipartite\n";
  return 0;    
}