/*
 Add 1 to number represented by a linkedlist
 Iterative Method
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
Node *reverse(Node *head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next;
    while(curr!=NULL)
      {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
    return prev;
}
Node *addoneUtil(Node *head)
{
    Node *res=head;
    Node *temp,*prev=NULL;
    int carry=1,sum;
    while(head!=NULL)
     {
         sum=carry+(head?head->data:0);
         carry=(sum>=10)?1:0;
         sum=sum%10;
         head->data=sum;
         temp=head;
         head=head->next;
     }
    if(carry>0)
      temp->next=newNode(carry);
    return res;
}
Node *addone(Node *head)
{
    head=reverse(head);
    head=addoneUtil(head);
    return reverse(head);
}
void printList(Node *head)
{
    while(head!=NULL)
     {
         cout<<head->data;
         head=head->next;
     }
     cout<<"\n";
}
int main()
{
 Node *head=newNode(9);
 head->next=newNode(9);
 head->next->next=newNode(9);
 head->next->next->next=newNode(9);
 cout<<"List is:\n";
 printList(head);
 head=addone(head);
 cout<<"Resultant List is:\n";
 printList(head);
}