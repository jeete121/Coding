#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    
    Node(int val) 
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
      Node *curr=head,*temp=NULL;
        if(head==NULL)
              return NULL;
    // insert duplicate node of every node into  the list
    while(curr)
      {
          temp=curr->next;

          //create new node with the same value as of the
          //current node
          curr->next=new Node(curr->val);

          //settle the pointers
          curr->next->next=temp;

          //move to the next node
          curr=temp;
      }
       curr=head;
      while(curr)
        {

            //if current next is present then
            //mark the current random pointer
            if(curr->next)
                  curr->next->random=curr->random?curr->random->next:curr->random;

            //move to the next node
            curr=curr->next?curr->next->next:curr->next;
        }
        Node *original=head,*copy=head->next;
        temp=copy;

       //settle the pointers in original and copy of
       //the list
        while(original&&copy)
        {

            //if original next present then
            //move original to next of next of original
            original->next=original->next?original->next->next:original->next;
            copy->next=copy->next?copy->next->next:copy->next;

            //move to the next node in original of linked
            //list
            original=original->next;

            //move to the next node in the copy of linked
            //ist
            copy=copy->next;
        }
        return temp;
}

//function to print the linked list
void printList(Node *head)
{
  Node *temp=head;
  cout<<"[";
  while(temp!=NULL)
    {
        cout<<"[";
        cout<<temp->val<<",";
        if(temp->random!=NULL)
          cout<<temp->random->val;
        else
         cout<<"null";
         cout<<"]";
        
        temp=temp->next;
        if(temp!=NULL)
          cout<<",";
        
    }
    cout<<"]";
}
int main()
{

  Node *head=new Node(1);
  head->next=new Node(2);
  Node *temp=head->next;
  head->random=head;
  temp->random=head;
  head->random=head;
  head=copyRandomList(head);
  printList(head);
  return 0;
}