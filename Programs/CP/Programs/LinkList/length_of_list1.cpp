/*
 Check if length of list is even or odd
 Time Complexity:O(N) where N are number  of nodes 
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
bool isEven(Node *head)
{
    if(head==NULL)
       return true;
    int cnt=0;
    while(head!=NULL)
      {
          cnt++;
          head=head->next;
      }
    if(cnt&1)
       return false;
    return true;
}
int main()
{
 Node *head=newNode(1);
 head->next=newNode(2);
 head->next->next=newNode(3);
 head->next->next->next=newNode(4);
 if(isEven(head))
    cout<<"Length of list is even\n";
 else 
   cout<<"Length of list is odd\n";
 return 0;
}