#include <bits/stdc++.h>
using namespace std;
//Structure of node
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
//Function to merge two
//Sorted Linklist
Node* mergeTwoLinkLists(Node* l1, Node* l2) 
{
        Node *temp1=l1,*temp2=l2;
        if(temp1==NULL && temp2==NULL)
               return NULL;
        if(temp1==NULL)
               return temp2;
        if(temp2==NULL)
               return temp1;
        Node *head=NULL,*temp=NULL;
        int flag=0;
        while(temp1&&temp2)
        {
            if(temp1->data<temp2->data)
            {
                if(flag==0)
                {
                    head=temp1;
                    flag=1;
                    temp=head;
                }
            else
            {
                temp->next=temp1;
                temp=temp1;
            }
               temp1=temp1->next;
               
            }
          else
          {
              if(flag==0)
              {
                  head=temp2;
                  flag=1;
                  temp=head;
              }
                  else
            {
                temp->next=temp2;
                temp=temp2;
            }
              temp2=temp2->next;
          }
        }
        if(temp1)
              temp->next=temp1;
        else if(temp2)
              temp->next=temp2;
        return head;
}
int main()
{
  Node *l1=new Node(1);
  l1->next=new Node(2);
  l1->next->next=new Node(4);
  Node *l2=new Node(1);
  l2->next=new Node(3);
  l2->next->next=new Node(4);
  l2->next->next->next=new Node(5);
  Node *head=mergeTwoLinkLists(l1,l2);
  while(head!=NULL)
    {
      cout<<head->data<<" ";
      head=head->next;
    }
   return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)
