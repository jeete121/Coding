#include <bits/stdc++.h>
using namespace std;

//function to add the new element
void addElement(stack<pair<int,int>> &st1,int value)
{
    int maximum;

    //if stack is empty 
    //then maximum element is the
    //new element
    if(st1.empty())
       maximum=value;
  
  //else the maximum element
  //is the max of stack top and current 
  //element
    else
      maximum=max(value,st1.top().second);

    //push the new element into the stack
    st1.push({value,maximum});
}

//function to find the maximum element
//of the queue
int findMaximumElement(stack<pair<int,int>> &st1,
             stack<pair<int,int>> &st2)
{

    //if both are empty return -1
    if(st1.empty()&&st2.empty())
       return -1;
    
    //if first is empty return
    //second top element
    else if(st1.empty())
       return st2.top().second;

    //if second is empty return
    //first top element 
    else if(st2.empty())
       return st1.top().second;

   //else return max of both
   //stacks
    else
      return max(st1.top().second,st2.top().second);
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
                 int maximum;
                 
                 //if second is empty
                 //maximum is the current element
                 if(st2.empty())
                   maximum=element;

                 //else the maximum
                 //is max of current element and
                 //stack top
                else
                  maximum=max(element,st2.top().second);
                
                //push into the new stack
                st2.push({element,maximum});
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
     addElement(st1,40);

     //print 40
     cout<<findMaximumElement(st1,st2)<<"\n";

     addElement(st1,60);
     addElement(st1,50);

    //print 60
    cout<<findMaximumElement(st1,st2)<<"\n";
     removeElement(st1,st2);

     //print 60
     cout<<findMaximumElement(st1,st2)<<"\n";
     return 0;

}