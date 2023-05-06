#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> st;
void add_element(int new_elem)
{
  int new_min;
 if(st.empty())
     new_min=new_elem;
 else
   new_min=min(new_elem,st.top().second);
 st.push({new_elem,new_min});
}
int  remove_element()
{
     if(st.empty())
        return -1;
     else
     {
         int removed_elem=st.top().first;
         st.pop();
         return removed_elem;
     }
     
}
int min_elem()
{
    if(st.empty())
       return -1;
    return st.top().second;
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
              add_element(new_elem);
          }
         else if(x==2)
           {
               int x=remove_element();
               if(x==-1)
                  cout<<"Stack is Empty\n";
               else   
                  cout<<x<<"\n";
           }
         else
         {
             int min1=min_elem();
             if(min1==-1)
                cout<<"Stack is Empty\n";
             else
                cout<<min1<<"\n";
         }
         
    }
}