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
//last node from the linked list
Node *deleteAtEnd(Node *head)
{
    //if linked list is
    //empty return NULL
    if(head==NULL||head->next==NULL)
       return NULL;
    Node *temp=head,*prev=head;
    //iterate till we reach
    //at the end of list
     while(temp->next!=NULL)
      {
          //store the previous
          //of the node
          prev=temp;
          temp=temp->next;
      }
      prev->next=NULL;
      free(temp);
      return head;
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
  head=deleteAtEnd(head);
  cout<<"Linked list after delete from end is \n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(1)
//Space Complexity: O(1)