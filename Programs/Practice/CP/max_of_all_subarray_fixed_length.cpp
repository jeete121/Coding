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
  int n,m;
  cin>>n>>m;
  int arr[n];
  for(int i=0;i<n;i++)
     cin>>arr[i];
  for(int i=0;i<m;i++)
     Insert(s1,arr[i]);
  cout<<"Min "<<getMin(s1,s2)<<"\n";
  for(int i=m;i<n;i++)
    {
        int p=Remove(s1,s2);
        Insert(s1,arr[i]);
        cout<<"Min "<<getMin(s1,s2)<<"\n";
    }
  return 0;
}