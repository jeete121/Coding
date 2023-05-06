#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> st1,st2;
int min_elem()
{
    if(st1.empty()||st2.empty())
        {
            if(st1.empty())
              {
                  if(st2.empty())
                     return -1;
                  return st2.top().second;
              }
            else
              return st1.top().second;
            
        }
      return min(st1.top().second,st2.top().second);
     
}
void add(int new_elem)
{
    int min1;
    if(st1.empty())
       min1=new_elem;
    else
      min1=min(new_elem,st1.top().second);
  st1.push({new_elem,min1});
}
int remove_elem()
{
    if(st2.empty())
       {
           while(!st1.empty())
             {
                 int element=st1.top().first;
                 st1.pop();
                 int min1;
                 if(st2.empty())
                    min1=element;
                 else
                    min(element,st2.top().second);
                st2.push({element,min1});
             }
       }
    if(st2.empty())
       return -1;
    int remove_element=st2.top().first;
    st2.pop();
    return remove_element;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
     {
         int x;
         cin>>x;
         if(x==1)
           {
               int new_elem;
              cin>>new_elem;
              add(new_elem);
           }
          else if(x==2)
            {
               int p=remove_elem();
               if(p==-1)
                  cout<<"Queue is Empty\n";
             else
                 cout<<p<<"\n";
            }
          else
           {
               int min1=min_elem();
               if(min1==-1)
                  cout<<"Queue is Empty\n";
              else
                 cout<<min1<<"\n";
           }
          
     }
    return 0;
}