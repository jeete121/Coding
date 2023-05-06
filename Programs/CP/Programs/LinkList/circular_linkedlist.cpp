/*
 Check if Linked List is Circular or not
 Time complexity: O(N) where N are number of nodes
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *newNode(int data)
{
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
bool isCircular(Node *head)
{
    Node *temp=head;
    if(head==NULL)
       return true;
    temp=temp->next;
    while(temp!=NULL&&temp!=head)
         temp=temp->next;
    if(temp==NULL)
       return false;
    return true;
}
int main()
{
  Node *head=newNode(1);
  head->next=newNode(2);
  head->next->next=newNode(3);
  if(isCircular(head))
     cout<<"Linked List is circular\n";
  else
    cout<<"Linked List is not circular\n";
   head->next->next->next=head;
  if(isCircular(head))
     cout<<"Linked List is circular\n";
  else
    cout<<"Linked List is not circular";
  return 0;
}