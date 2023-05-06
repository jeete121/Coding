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
//Function to swap nodes in pair in
//linklist
Node *swapPairs(Node *head)
{
    if(head==NULL||head->next==NULL)
       return head;
    Node *temp=head;
    while(temp!=NULL)
      {
          if(temp->next!=NULL)
           {
               int val=temp->data;
               temp->data=temp->next->data;
               temp->next->data=val;
               temp=temp->next;
           }
        temp=temp->next;
      }
      return head;
}
int main()
{
  Node *head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);
  head=swapPairs(head);
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