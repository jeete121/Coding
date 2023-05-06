#include <bits/stdc++.h>
using namespace std;
int getMin(deque<int> &q)
{
    if(!q.empty())
      return q.front();
    return INT_MAX;
}
void Insert(deque<int> &q,int new_element)
{
    while(!q.empty()&& q.back()>new_element)
        q.pop_back();
    q.push_back(new_element);
}
int Remove(deque<int> &q,int remove_element)
{
    if(!q.empty()&& q.front()==remove_element)
      {
          q.pop_front();
          return remove_element;
      }
    return INT_MAX;
}
int main()
{
  deque<int> q;
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
           cin>>x;
           int p=Remove(q,x);
           if(p==x)
             cout<<"Popped\n";
           else
             cout<<"No pop\n";
           
       }
    else if(a==3)
      {
        int p=getMin(q);
        if(p==INT_MAX)
           cout<<"Queue is Empty:\n";
        else
           cout<<"Minimum Element is: "<<p<<"\n";
      }
    else
     break;    
   }
}