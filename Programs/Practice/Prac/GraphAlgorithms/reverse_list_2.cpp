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

Node* reverseBetween(Node* head, int n, int m) 
{
       
    //if list is empty or n==m
    //then return the original list
    if(head==NULL||n==m)
      return head;

    //varibale to hold the count
    //of nodes
    int count=0;

    //varible to hold the previous of n
    //mth node and the nth node
    Node *temp=head,*prevN=head,*nthNode=head,*mthNode=head;
    while(temp!=NULL)
     {
       count++;
      if(count<n)
        {
            prevN=temp;
        }
      if(count==n)
       {
           nthNode=temp;
       }
      if(count==m)
        {
            mthNode=temp;
            temp=temp->next;
            break;
        }
        temp=temp->next;
        
     }
    Node *reverse=NULL,*curr=nthNode,*curr1=nthNode,*first=nthNode;
    while(curr!=temp)
      {
        curr=curr->next;
        curr1->next=reverse;
        reverse=curr1;
        curr1=curr;
      }
    prevN->next=reverse;
    first->next=temp;
    if(n==1)
      head=reverse;
    return head; 
}

//function to traverse a linked 
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
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    int m=2,n=4;
    head=reverseBetween(head,m,n);
    linkedListTraversal(head);
}