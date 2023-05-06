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
//function to delete the
//given node from the linked list
Node *deleteGivenNode(Node *head,int value)
{
    //if linked list is
    //empty return NULL
    if(head==NULL)
       return NULL;
    if(head->data==value)
      {
          head=head->next;
          return head;
      }
    Node *temp=head,*prev=head;
    //iterate till we reach
    //at the end of list
     while(temp!=NULL)
      {
          //if we found the node
          // then break
        if(temp->data==value)
         {
             break;
         }
         //else move to the next node
         else
          {
              prev=temp;
              temp=temp->next;
          }
      }
      //if node is not found 
      //in the list then just return
      //the original list
      if(temp==NULL)
         return head;
     //delete the the given node
      else
      {
      prev->next=temp->next;
      //free the given node
      free(temp);
      //return the head
      return head;
      }
}
//function to traverse(print) a linked 
//list
void linkedListTraversal(Node *head)
{
    Node *temp=head;
    //iterate till we reach end of the linked 
    //list
    while(temp!=NULL)
     {
         //print the current
         //node data
         cout<<temp->data<<" ";
         //move to next node
         temp=temp->next;
     }
}
int main()
{
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  cout<<"Linked list befor delete is\n";
  linkedListTraversal(head);
  cout<<"\n";
  int value=8;
  head=deleteGivenNode(head,value);
  cout<<"Linked list after delete given node is \n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)