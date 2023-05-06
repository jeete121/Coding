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

//function to check the linked
//list is palindrome or not
bool isPalindrome(Node* head) 
{
    Node *temp=head,*temp1=head,*curr=head,*prev=NULL,*curr1;

    //iterate till end of list
    //and move one pointer
    //once and one pointer twice
    while(temp!=NULL)
      {
         temp=temp->next;
    
         if(temp!=NULL)
          {
             temp1=temp1->next;
             temp=temp->next;
          }
      }

      //revers the half list
    curr1=temp1;
    while(temp1!=NULL)
     {
        curr1=temp1->next;
        temp1->next=prev;
        prev=temp1;
        temp1=curr1;
        
     }

//check the first half list
//with reverse of second half
while(curr!=NULL && prev!=NULL)
  {

   if(curr->data!=prev->data)
        return false;
    else
    {
        curr=curr->next;
        prev=prev->next;
    }
  }
  return true;
}

int main()
{
    
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(2);
  head->next->next->next->next=new Node(5);

  if(isPalindrome(head))
     cout<<"Palindrome\n";
 else
   cout<<"Not Palindrome\n";
 
  return 0;
}