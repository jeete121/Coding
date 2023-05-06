/*
 Two string represented as two linked list
 Compare two strings
 Time Complexity: O(N) where N is the minimum  of two list
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string data;
    Node *next;
};
Node *newNode(string data)
{
    Node *new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
int compareTwoListString(Node *head1,Node *head2)
{
    if(head1==NULL && head2==NULL)
       return 0;
    while(head1!=NULL&& head2!=NULL)
     {
         if(head1->data>head2->data)
            return 1;
         if(head1->data<head2->data)
            return -1;
         head1=head1->next;
         head2=head2->next;
     }
    if(head1!=NULL)
       return 1;
    if(head2!=NULL)
       return -1;
    return 0;
}
int main()
{
 Node *head1=newNode("a");
 head1->next=newNode("c");
 //head1->next->next=newNode("b");
 Node *head2=newNode("a");
 head2->next=newNode("b");
 head2->next->next=newNode("c");
 if(compareTwoListString(head1,head2)==0)
    cout<<"Both strings are equal\n";
 else if(compareTwoListString(head1,head2)==1)
   cout<<"String first is lexicographcally greater\n";
 else
  cout<<"String second is lexicographically greater\n";
  return 0;
 
}