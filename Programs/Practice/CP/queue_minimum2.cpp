#include <bits/stdc++.h>
using namespace std;
int cnt_added=0,cnt_removed=0;
int getMin(deque<pair< int, int > > &q)
{
    if(!q.empty())
      return q.front().first;
    return INT_MAX;
}
void Insert(deque<pair < int, int > > &q,int new_element)
{
    while(!q.empty()&& q.back().first>new_element)
        q.pop_back();
    q.push_back({new_element,cnt_added});
    cnt_added++;
}
void  Remove(deque<pair< int,int > > &q)
{
    if(!q.empty()&& q.front().second==cnt_removed)
          {

              q.pop_front();
             
          }
cnt_removed++;
}
int main()
{
  deque<pair< int,int > > q;
  /*
   a=1:insert(x)
   a=2:remove(x)
   a=3:minelement()
   a=4:exit
  */
  int a,x;
  while(1)
   {
     cin>>a;
     if(a==1)
       {
           cin>>x;
           Insert(q,x);
       }
     else if(a==2)
       {
          Remove(q);
           
       }
    else if(a==3)
   {
       int p=getMin(q);
       if(p==INT_MAX)
          cout<<"Queue is Empty\n";
       else
          cout<<"Minimum Element is: "<<p<<"\n";
   }
    else
     break;    
   }
}