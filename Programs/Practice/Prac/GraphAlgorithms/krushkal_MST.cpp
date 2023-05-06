#include <bits/stdc++.h>
using namespace std;

//structure of edge
//i.e a->b with weight w
struct Edge
{
    int a,b,w;
};
Edge arr[1000001];

//array of parent of
//each nodes
int parent[100001];

//array to have size of
//the set
int size1[100001];

//make the set 
void make_set(int n)
{
    for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size1[i]=1;
        }
}

//find in which set
//the particular element
//is present
int find(int a)
{
    if(a==parent[a])
       return a;
    return parent[a]=find(parent[a]);
}

//union of 2 sets
void union_set(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
       {
           if(size1[a]<size1[b])
              swap(a,b);
            parent[b]=a;
            size1[a]+=size1[b];
       }
}

//comparator used to
//sort the edges by  the weights
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

void KrushkalSAlgorithm(int m)
{

    //variable to hold the
    //cost of MST
    int MSTCost=0;

    //vector to hold the
    //which edges are into the MST
    vector<Edge> res;

    //sort the edges according
    //to the weights
    sort(arr,arr+m,cmp);

    //iterate for all the edges
    for(int i=0;i<m;i++)
       {
           //fisrt point of edge
           int a=arr[i].a;

           //last point of edge
           int b=arr[i].b;

           //find in which sets they are belongs
           a=find(a);
           b=find(b);

           //if both are in different sets
           if(a!=b)
             {
                 //use this edge into MST
                 MSTCost+=arr[i].w;

                 //add this edge into MST edge
                 Edge e;
                 e.a=arr[i].a;
                 e.b=arr[i].b;
                 e.w=arr[i].w;
                 res.push_back(e);

                 //make union
                 union_set(a,b);
             }
       }

       //print the edges which are into
       //the MST of the graph
       cout<<"MST Edges\n";
       for(Edge e:res)
         {
           cout<<e.a<<" "<<e.b<<" "<<e.w<<"\n";
         }

      //print the cost of MST
       cout<<"MST Cost\n";
       cout<<MSTCost<<"\n";
}
int main()
{

    int n=4;
    int m=5;
    make_set(n);
    //add edges first edge
    arr[0].a=1; arr[0].b=2; arr[0].w=5;
    
    //second edge
    arr[1].a=2; arr[1].b=3; arr[1].w=3;
    
    //third edge
    arr[2].a=3; arr[2].b=1;arr[2].w=4;

    //4th edge
     arr[3].a=1; arr[3].b=4;arr[3].w=2;
     
     //5th edge
     arr[4].a=4; arr[4].b=3; arr[4].w=6;
     KrushkalSAlgorithm(m);
     return 0;
      
}
//Time Complexity: O(mlog(n))
