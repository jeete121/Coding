#include <bits/stdc++.h>
using namespace std;

//function to add the new element
void addElement(stack<pair<int,int>> &st1,int value)
{
    int minimum;

    //if stack is empty 
    //then minimum element is the
    //new element
    if(st1.empty())
       minimum=value;
  
  //else the minimum element
  //is the min of stack top and current 
  //element
    else
      minimum=min(value,st1.top().second);

    //push the new element into the stack
    st1.push({value,minimum});
}

//function to find the minimum element
//of the queue
int findMinimumElement(stack<pair<int,int>> &st1,stack<pair<int,int>> &st2)
{

    //if both are empty return -1
    if(st1.empty()&&st2.empty())
       return -1;
    
    //if fisrt is empty return
    //second top element
    else if(st1.empty())
       return st2.top().second;

    //if second is empty return
    //fisrt top element 
    else if(st2.empty())
       return st1.top().second;

   //else return min of both
   //stacks
    else
      return min(st1.top().second,st2.top().second);
}

//function to remove the element
void removeElement(stack<pair<int,int>> &st1,stack<pair<int,int>> &st2)
{

    //if second is empty
    if(st2.empty())
      {

          //this means convert the stack into
          //queue
          while(!st1.empty())
             {

                 int element=st1.top().first;
                 st1.pop();
                 int minimum;
                 
                 //if second is empty
                 //minimum is the current element
                 if(st2.empty())
                   minimum=element;

                 //else the minimum
                 //is min of current element and
                 //stack top
                else
                  minimum=min(element,st2.top().second);
                
                //push into the new stack
                st2.push({element,minimum});
             }
      }
    //if second stack is not 
    //empty then pop the top
    //element
    if(!st2.empty())
      st2.pop();
}
int main()
{
    stack<pair<int,int>> st1,st2;

     addElement(st1,5);
     addElement(st1,3);
     addElement(st1,10);

     //print 3
     cout<<findMinimumElement(st1,st2)<<"\n";

     addElement(st1,2);
     addElement(st1,4);

    //print 2
    cout<<findMinimumElement(st1,st2)<<"\n";
     removeElement(st1,st2);

     //print 2
     cout<<findMinimumElement(st1,st2)<<"\n";
     return 0;

}