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

//function to delete the node
//without head
void deleteNode(Node *node)
{
    //base case if not NULL
    if(node==NULL)
              return;

    if(node->next==NULL)
          {
              return;
          }
    else
    {
      //varible to hold the next
      //of node
      Node *temp;
      temp=node->next;
      //copy data of temp
      //into node
      node->data=temp->data;
      //make pointer of node to
      //next  of temp
      node->next=temp->next;

      //free temp
      delete temp;
    }
}
int main()
{
    
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  Node *node=head->next->next;  //i.e 8
  deleteNode(node);
  cout<<"List After delete\n";
  linkedListTraversal(head);
  return 0;
}