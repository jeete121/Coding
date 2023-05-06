#include <bits/stdc++.h>
using namespace std;
//Struture of  node
struct Node
{ 
   int data;
   Node *next;
   Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

//function to check if linked
// list contains cycle or not
bool hasCycle(Node *head)
{
  Node *slow=head,*fast=head;

  //move slow pointer one time and
  //fast pointer 2 times
  while(fast!=NULL)
    {
        fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;

                //if both slow and fast are
                //at same place then return true
                //means cycle is present
                if(slow==fast)
                      return true;
            }
    }

  //no cycle
  return false;
}

int main()
{
    Node *head=new Node(3);
    head->next=new Node(2);
    Node *temp=head->next;
    head->next->next=new Node(0);
    head->next->next->next=new Node(-4);
    head->next->next->next->next=temp;
    if(hasCycle(head))
       cout<<"Cycle\n";
    else
      cout<<"No Cycle\n";
    return 0;
}