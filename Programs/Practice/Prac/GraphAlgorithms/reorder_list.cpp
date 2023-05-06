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

void reorderList(Node* head) 
{
       stack<Node*> st;
       queue<Node*> q;
       
        if(head==NULL||head->next==NULL)
              return ;
         Node *temp=head->next;
       while(temp!=NULL)
       {
           st.push(temp);
           q.push(temp);
           temp=temp->next;
       }
       temp=head;
       Node *temp1=NULL;
       while(true)
       {
          if(st.top()==q.front())
          {
              temp->next=q.front();
              temp->next->next=NULL;
              break;
          }
          temp->next=st.top();
           st.pop();
           temp=temp->next;
          temp->next=q.front();
          q.pop();
          temp1=temp->next;
           temp=temp->next;
           if(temp1==st.top())
           {
               temp->next=NULL;
               break;
           }
       }
}

//function to traverse a linked 
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

int main()
{
  Node *head=new Node(1);
  head->next=new Node(2);
  head->next->next=new Node(3);
  head->next->next->next=new Node(4);

  reorderList(head);
  linkedListTraversal(head);
  return 0;
}