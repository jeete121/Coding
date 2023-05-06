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
//first node from the linked 
//list
Node *deleteAtBeginning(Node *head)
{
    //if linked list is
    //empty return NULL
    if(head==NULL)
       return NULL;
    //store the first elemnt
    Node *temp=head;
    //
    head=head->next;
    //delete the first node
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
  head=deleteAtBeginning(head);
  cout<<"Linked list after delete from beginning is \n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(1)
//Space Complexity: O(1)