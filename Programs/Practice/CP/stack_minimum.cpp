#include <bits/stdc++.h>
using namespace std;
void Insert(stack< pair<int, int > > &st,int x)
{
    int min1;
    if(!st.empty())
       min1=min(x,st.top().second);
    else
     min1=x;
   st.push({x,min1}); 
}
int Remove(stack< pair <int ,int > > &st)
{
    if(!st.empty())
       {
           int x=st.top().first;
           st.pop();
           return x;
       }
    else
       return INT_MAX;
    
}
int getMin(stack< pair <int, int > > &st)
{
    if(!st.empty())
       return st.top().second;
    return INT_MAX;
}

int main()
{
  stack< pair <int, int > > st;
  /*
   a=1:push(x)
   a=2:pop()
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
           Insert(st,x);
       }
     else if(a==2)
       {
           int p=Remove(st);
           if(p==INT_MAX)
              cout<<"Stack is empty\n";
          else
          cout<<"Poped element is: "<<p<<"\n";
       }
    else if(a==3)
        cout<<"Minimum Element is: "<<getMin(st)<<"\n";
    else
     break;    
   }
}