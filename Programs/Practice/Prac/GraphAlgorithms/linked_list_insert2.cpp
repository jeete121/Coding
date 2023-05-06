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
//function to insert the node after
//given node 
Node *insertAfterGivenNode(Node *head,int aftervalue,int value)
{
  
    if(head==NULL)
      {
          //if head is null 
          //then insert at the end of 
          //the linked list
          head=insertAtEnd(head,value);
          //return head of the linked list
          return head;
      }
      Node *temp=head;
      while(temp!=NULL)
       {
           //if current head data
           //is same as the aftervalue 
           //then break
           if(temp->data==aftervalue)
              {
                  break;
              }
           //move to the next node
            else
            {
               temp=temp->next;   
            }
       }
     //if node is not find
     //then insert at the end 
     //of the linked list
      if(temp==NULL)
        {
            head=insertAtEnd(head,value);
            //return the head of
            //the linked list
            return head;
        }
     else
     {
         //create the new node
         Node *newNode=new Node(value);
         //insert the node after given node
         newNode->next=temp->next;
         temp->next=newNode;
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
  cout<<"Linked list befor insert is\n";
  linkedListTraversal(head);
  cout<<"\n";
  int aftervalue=8,value=12;
  head=insertAfterGivenNode(head,aftervalue,value);
  cout<<"Linked list after insert is \n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)