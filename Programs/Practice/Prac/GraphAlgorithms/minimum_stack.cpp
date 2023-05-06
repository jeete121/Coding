#include <bits/stdc++.h>
using namespace std;

//function to add the new element 
//into the stack
void addElement(stack<pair<int,int>> &st,int value)
{
   int new_min;
   
   //if stack is empty then
   //the minimum element is the given 
   //elememt
   if(st.empty())
      new_min=value;

  //else the minimum element is
  //the min of stack top and current elememt
  else
    new_min=min(st.top().second,value);

  //push the current element
  //with the minimum element
  st.push({value,new_min});
}

//function to remove the
//top of the stack
void removeElement(stack<pair<int,int>> &st)
{
    //if not empty 
    if(!st.empty())
       {
           int removed_element=st.top().first;

           //remove the to element from the stack
           st.pop();
       }

}

//function to find the
//minimum element of the stack
int findMinimumElement(stack<pair<int,int>> &st)
{
    //if stack is empty
    //return -1
    if(st.empty())
       return -1;
    
    //else return the minimum element from
    //the stack
    else 
      return st.top().second;
}
int main()
{
   //stack pair to hold the element and the
   //minimum at the top of stack
   stack<pair<int,int>> st;
   addElement(st,10);
   addElement(st,23);
   addElement(st,5);

   //print 5
   cout<<findMinimumElement(st)<<"\n";
   addElement(st,6);
   addElement(st,3);

   //print 3
   cout<<findMinimumElement(st)<<"\n";
   removeElement(st);

   //print 5
   cout<<findMinimumElement(st)<<"\n";
   return 0;
}