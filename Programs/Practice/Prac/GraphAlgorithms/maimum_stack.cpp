#include <bits/stdc++.h>
using namespace std;

//function to add the new element 
//into the stack
void addElement(stack<pair<int,int>> &st,int value)
{
   int new_max;
   
   //if stack is empty then
   //the maximum element is the given 
   //elememt
   if(st.empty())
      new_max=value;

  //else the maximum element is
  //the max of stack top and current elememt
  else
    new_max=max(st.top().second,value);

  //push the current element
  //with the maximum element
  st.push({value,new_max});
}

//function to remove the
//top of the stack
void removeElement(stack<pair<int,int>> &st)
{
    //if not empty 
    if(!st.empty())
       {
           int removed_element=st.top().first;

           //remove the top element from the stack
           st.pop();
       }

}

//function to find the
//maximum element of the stack
int findMaximumElement(stack<pair<int,int>> &st)
{
    //if stack is empty
    //return -1
    if(st.empty())
       return -1;
    
    //else return the maximum element from
    //the stack
    else 
      return st.top().second;
}
int main()
{
   //stack pair to hold the element and the
   //maximum at the top of stack
   stack<pair<int,int>> st;
   addElement(st,10);
   addElement(st,23);
   addElement(st,5);

   //print 23
   cout<<findMaximumElement(st)<<"\n";
   addElement(st,6);
   addElement(st,123);

   //print 123
   cout<<findMaximumElement(st)<<"\n";
   removeElement(st);

   //print 23
   cout<<findMaximumElement(st)<<"\n";
   return 0;
}