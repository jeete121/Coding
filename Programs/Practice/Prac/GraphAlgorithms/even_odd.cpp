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
//function to find partition
//the even odd value node
//in linked list
Node *oddEven(Node *head)
{
   //if head is null
    if(head==NULL)
       return head;
    //varibales to hold even list ,odd list,even head,odd head
    Node *even=NULL,*odd=NULL,*oddhead=NULL,*evenhead=NULL;
    Node *temp=head;
    int flag=0,flag1=0;
    //iterate till the end
    //of the linked list
    while(temp!=NULL)
     {
         //if data is odd 
         //insert into the odd 
         //list
        if(temp->data&1)
           {
               //if the element is first odd
               if(flag==0)
                 {
                     odd=temp;
                     //store the head
                     oddhead=temp;
                     //make flag as 1
                     flag=1;
                 }
                else
                {
                    //add the new into next 
                    //of the add list
                    odd->next=temp;
                    //make odd ad temp
                    odd=temp;
                }
              //move to the next node
              temp=temp->next;
                
           }
         else
         {
             //if data is first even
             if(flag1==0)
              {
                  even=temp;
                  //make head as the given node
                  evenhead=temp;
                  // make flag=1
                  flag1=1;
              }
              else
              {
                  //add into the even 
                  //linked list
                  even->next=temp;
                  //move even to the temp
                  even=temp;
              }
              //move the node to next node
              temp=temp->next;
         }
     }
     //if their are  no odd nodes
     if(flag==0)
        return evenhead;
    //if  their are no even nodes
     if(flag1==0)
        return oddhead;
     //make even next as null
     even->next=NULL;
     //append the even list 
     //at the end of odd
     //list
     odd->next=evenhead;
     //return the odd head
     return oddhead;
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
  cout<<"Original Linked list is\n";
  linkedListTraversal(head);
  head=oddEven(head);
  cout<<"\n";
  cout<<"Linked list after odd-even \n";
  linkedListTraversal(head);
  return 0;
}
//Time Complexity: O(n)