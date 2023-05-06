/*
 Add 1 to number represented by a linkedlist
 Recusive Method
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
int addWithcarry(Node *head)
{
    if(head==NULL)
       return 1;
    int res=head->data+addWithcarry(head->next);
    head->data=res%10;
    return res/10;
}
Node *addOne(Node *head)
{
    int carry=addWithcarry(head);
    if(carry>0)
    {
        Node *newNode=new Node;
        newNode->data=carry;
        newNode->next=head;
        return newNode;
    }
    return head;

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
 head=addOne(head);
 cout<<"Resultant List is:\n";
 printList(head);
}