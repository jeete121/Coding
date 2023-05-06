/*
 Add 2 numbers represented as
 linked list
 Time Complexity O(N+M)
 where N and M are lengths of the lists
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
Node *addTwoList(Node *head1,Node *head2)
{
    Node *res=NULL;
    Node *temp,*prev=NULL;
    int carry=0,sum;
    while(head1!=NULL||head2!=NULL)
     {
         sum=carry+(head1?head1->data:0)+(head2?head2->data:0);
         carry=(sum>=10)?1:0;
         sum=sum%10;
         temp=newNode(sum);
         if(res==NULL)
            res=temp;
        else
           prev->next=temp;
        prev=temp;
        if(head1)
           head1=head1->next;
        if(head2)
            head2=head2->next;
     }
    if(carry>0)
      temp->next=newNode(carry);
    return res;
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

    Node* res = NULL;  
    Node* first = NULL;  
    Node* second = NULL; 
    first=newNode(1);
    first->next=newNode(2);
    first->next->next=newNode(3);
    cout<<"First list is: ";
    printList(first);
    second=newNode(2);
    second->next=newNode(4);
    cout<<"Second list is: ";
    printList(second); 
    res=addTwoList(reverse(first),reverse(second));
    cout<<"Resultant List is: ";
    printList(reverse(res));
}