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
//Function to reverse the linklist
Node *reverseList(Node *head)
{
    if(head==NULL)
       return head;
    Node *curr=head,*prev=NULL,*temp=head;
    while(curr!=NULL)
      {
         temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
      }
    return prev;
}
int main()
{
  Node *head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(5);
  head=reverseList(head);
  Node *temp=head;
  while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)