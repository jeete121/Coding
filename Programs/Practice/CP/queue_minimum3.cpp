#include <bits/stdc++.h>
using namespace std;
void Insert(stack<pair<int, int > > &s1,int new_element)
{
 int minimum;
 if(s1.empty())
    minimum=new_element;
 else
   minimum=min(new_element,s1.top().second);
 s1.push({new_element,minimum});      
}
int getMin(stack<pair<int,int> > &s1,stack<pair <int ,int > > &s2)
{
    int minimum;
    if(s1.empty()||s2.empty())
      {
          if(s1.empty())
            { 
                if(s2.empty())
                  minimum=INT_MAX;
                else
                   minimum=s2.top().second;
            }
          else
          {
            if(s2.empty())
              minimum=s1.top().second;
            else            
              minimum=min(s1.top().second,s2.top().second);          
      }
    }
    else
     minimum=min(s1.top().second,s2.top().second);
    return minimum;
}
int Remove(stack<pair<int ,int > > &s1,stack<pair <int, int > >&s2)
{
    if(s2.empty())
     {
         while(!s1.empty())
           {
               int element=s1.top().first;
               s1.pop();
               int minimum;
               if(s2.empty())
                 minimum=element;
               else
                minimum=min(element,s2.top().second);
               s2.push({element,minimum});
           }
     }
     int remove_element;
   if(s2.empty())
      remove_element=INT_MAX;
  else
  {
  
  remove_element=s2.top().first;
   s2.pop();
  }
   return remove_element;
}
int main()
{
  stack<pair<int ,int > > s1,s2;
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
           Insert(s1,x);
       }
     else if(a==2)
       {
           int p=Remove(s1,s2);
           if(p==INT_MAX)
             cout<<"Queue is Empty\n";
           else
             cout<<"Popeed Element is: "<<p<<"\n";
           
       }
    else if(a==3)
      {
        int p=getMin(s1,s2);
        if(p==INT_MAX)
           cout<<"Queue is Empty:\n";
        else
           cout<<"Minimum Element is: "<<p<<"\n";
      }
    else
     break;    
   }
  return 0;
}