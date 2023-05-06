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

//function to reverse a linlked list
Node * reverse(Node *root)
{
    Node *temp=root,*prev=NULL,*curr=root;
        while(temp!=NULL)
        {
           curr=curr->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
}

//function to add two linked list
Node* addTwoNumbers(Node* l1, Node* l2) 
{
    int x=0,y=0,z,l=0;
    l1=reverse(l1);
    l2=reverse(l2);
    Node *temp1=l1,*temp2=l2,*start=NULL,*temp;

    //iterate till their is any lint
    //is not null
    while(temp1!=NULL || temp2!=NULL)
     {

        //if first list is not null
       if(temp1!=NULL)
       {
        x=temp1->data;
           temp1=temp1->next;
       }
     //if first list is null
      else if(temp1==NULL) 
        x=0;

     //if second list is not null
     if(temp2!=NULL)
      {
       y=temp2->data;
          temp2=temp2->next;
      }

     //if second list is null
   else if(temp2==NULL)
       y=0;
       z=x+y+l;

     //create new node
     Node *newNode=new Node(z%10);
         newNode->next=NULL;
         if(start==NULL)
         {
             start=newNode;
             temp=start;
         }
         else
         {
         temp->next=newNode;
         temp=temp->next;}
     l=z/10;
     }
     if(l>0)
     {
          Node *newNode=new Node(l);
         newNode->next=NULL;
        temp->next=newNode;
         temp=temp->next;
     }
        start=reverse(start);
      //return the new list head
        return start;
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
    Node *head1=new Node(7);
    head1->next=new Node(2);
    head1->next->next=new Node(4);
    head1->next->next->next=new Node(3);

    Node *head2=new Node(5);
    head2->next=new Node(6);
    head2->next->next=new Node(4);

    Node *newlist=addTwoNumbers(head1,head2);

    linkedListTraversal(newlist);
    return 0;

}