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
//function to traverse(print) a linked 
//list
void linkedListTraversal(Node *head)
{
    Node *temp=head;
    //iterate till we reach end of the linked 
    //list
    while(temp!=NULL)
     {
         //print the current
         //node data
         cout<<temp->data<<" ";
         //move to next node
         temp=temp->next;
     }
}

//insert the node at its correct position
Node *SortedList(Node *head,Node *new_node)
    {
        if(head==NULL ||head->data>=new_node->data)
        {
            new_node->next=head;
            head=new_node;
            return head;
        }
      else
      {
          Node *temp=head;
          while(temp->next!=NULL&&temp->next->data<new_node->data)
              temp=temp->next;
          new_node->next=temp->next;
          temp->next=new_node;
      }
        return head;
}

//function to sort the linked
//list
Node* insertionSortList(Node* head) 
{
        Node *temp=head;
        Node *ans=NULL;
        while(temp!=NULL)
        {
          Node *curr=temp->next;
          ans=SortedList(ans,temp);
            temp=curr;
        }
     return ans;
}
int main()
{
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  head=insertionSortList(head);
  cout<<"List after sort is\n";
  linkedListTraversal(head);
  return 0;
}