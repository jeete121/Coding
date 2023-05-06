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
//function to find the length
//of a linked list
int  linkedListLength(Node *head)
{
    Node *temp=head;
    int length=0;
    //iterate till we reach end of the linked 
    //list
    while(temp!=NULL)
     {
         //increment the length
         length++;
         //move to next node
         temp=temp->next;
     }
     //return the length
     return length;
}
int main()
{
 
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  cout<<"Length of Linked list is ";
  cout<<linkedListLength(head);
  return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)