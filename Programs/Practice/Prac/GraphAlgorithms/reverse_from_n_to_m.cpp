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
//function to reverse nodes from
//n to m
Node *reverseFromNToM(Node *head,int n,int m)
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

    //iterate till the end of list 
    while(temp!=NULL)
     {
        //increment the count
         count++;
    
      //if count is less than n then
      //update previous of n
       if(count<n)
        {
            prevN=temp;
        }

        //if count is same as n
        //then update nthNode
      if(count==n)
       {
           nthNode=temp;
       }

       //if count is same as
       //m then update mthNode
       //and break out of loop
      if(count==m)
        {
            mthNode=temp;

            //temp store the next of mthNode
            temp=temp->next;
            break;
        }
        temp=temp->next;
        
     }

     //now varible for reverse
    Node *reverse=NULL,*curr=nthNode,*curr1=nthNode,*first=nthNode;

    //iterae tiil curr is not 
    //eqaul to temp
    while(curr!=temp)
      {
        curr=curr->next;
        curr1->next=reverse;
        reverse=curr1;
        curr1=curr;
      }

    //update the pointers in new list
    prevN->next=reverse;
    first->next=temp;

    //if n is 1 then
    //new head will we the reverse
    if(n==1)
      head=reverse;

    //return the head
    return head;
}
int main()
{
  Node *head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(5);
  head->next->next->next->next->next=new Node(6);
   head->next->next->next->next->next->next=new Node(7);
  int n=2,m=4;

  head=reverseFromNToM(head,n,m);
  Node *temp=head;
  cout<<"New List is\n";
  while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)