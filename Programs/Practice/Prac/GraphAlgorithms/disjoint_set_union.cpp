#include <bits/stdc++.h>
using namespace std;
int parent[10001];

//function to make the set
//of each element as itself
//as thier parent
void make_set(int n)
{
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

//find the set in which 
//the given node is
//present
int find_set(int v)
{
    if(v==parent[v])
        return v;
    return find_set(parent[v]);
}


//function to union 
//of two sets in which a
//and b present
void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
       parent[b]=a;
}
int main()
{
  int n=5;
  make_set(n);

  //combibe the set in which
  //1 and 2 occur
  union_sets(1,2);
  //combibe the set in which
  //3 and 4 occur
  union_sets(3,4);

  //find set in which 1
  //is prenent
  cout<<find_set(1)<<"\n";

  //union of 3 and 5
  union_sets(3,5);
  //find the set in which 5
  //is present
  cout<<find_set(5)<<"\n";

}