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

Node* rotateRight(Node* head, int k) 
{
        int n=0;
        Node *temp=head,*temp1=head;
        if(temp==NULL||k==0)
              return temp;
        while(temp!=NULL)
          { 
             temp=temp->next;
             n++;
          }
        k=k%n;
        if(k==0)
             return head;
        int x=n-k;
        Node *prev=head;
        while(temp1&&x)
        {
            prev=temp1;
            temp1=temp1->next;
            x--;
        }
         prev->next=NULL;
        Node *p=temp1;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=head;
        head=p;
        return head;
}
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
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    int k=2;
    head=rotateRight(head,k);
    linkedListTraversal(head);
    return 0;

}