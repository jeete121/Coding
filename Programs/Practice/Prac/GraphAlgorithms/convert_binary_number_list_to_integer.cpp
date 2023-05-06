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

int getDecimalValue(Node* head) 
{
       Node *temp=head,*curr,*prev=NULL;
       while(temp!=NULL)
        {
           curr=temp;
           temp=temp->next;
           curr->next=prev;
           prev=curr;
        }
        int i=0;
        int  ans=0;
        Node *temp1=prev;
        while(temp1!=NULL)
         {
             if(temp1->data==1)
                    ans+=pow(2,i);
             i++;
            temp1=temp1->next;
         }
        return ans;
}

int main()
{
  Node *head=new Node(1);
  head->next=new Node(0);
  head->next->next=new Node(1);
  cout<<getDecimalValue(head);
  return 0;
}  