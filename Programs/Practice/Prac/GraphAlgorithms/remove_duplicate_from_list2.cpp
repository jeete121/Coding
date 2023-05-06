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


//function to remove the duplicate elements
//in linked list
Node* deleteDuplicates(Node* head)
{
        Node *root=NULL,*temp=head;
        if(head==NULL)
              return head;
       Node *prev=NULL,*temp1=NULL;
        int flag=0;
        int x;
        int cnt;
        while(temp!=NULL)
         {
            prev=temp;
           x=prev->data;
            temp=temp->next;
           cnt=1;
            while(temp!=NULL&&(temp->data==x))
            {
                cnt++;
                temp=temp->next;
            }
        
            if(cnt==1)
            {

                if(flag==0)
                {
                    root=prev;
                    temp1=root;
                    flag=1;
                }
               else
               {
                  temp1->next=prev;
                   temp1=temp1->next;
               }
            }

        }
        if(temp1!=NULL)
           temp1->next=NULL;
        return root;
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
    head->next=new Node(1);
    head->next->next=new Node(1);
    head->next->next->next=new Node(2);
    head->next->next->next->next=new Node(3);

    head=deleteDuplicates(head);
    linkedListTraversal(head);
    return 0;

}