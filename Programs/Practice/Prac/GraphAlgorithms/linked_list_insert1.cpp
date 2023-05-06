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
//funtion to add the node 
//at end of the linked list
Node *insertAtEnd(Node *head,int value)
{
    //if list is the list is empty
    //then the new node is the only 
    //node in list 
    if(head==NULL)
     {
         //create a new Node
         Node *newNode=new Node(value);
         //point head to the 
         //new Node
         head=newNode;
         //return head
         return head;
     }
    else
    {
       Node *temp=head;
       //iterarte till we reach at last
       //node of the linked list
       while(temp->next!=NULL)
        {
            //move to the next node
            temp=temp->next;
        }
        //create a new node
        Node *newNode=new Node(value);
        //point the last node to
        //the new node
        temp->next=newNode;
        //return the head of the 
        //linked list
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
  cout<<"Linked list befor inert\n";
  linkedListTraversal(head);
  cout<<"\n";
  int value=12;
  head=insertAtEnd(head,value);
  cout<<"Linked list after inserting at end is\n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)