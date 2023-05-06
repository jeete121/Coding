#include <bits/stdc++.h>
using namespace std;

//structure for linkedlist
struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode *child;
    ListNode(int val)
    {
      this->data=val;
      this->prev=NULL;
      this->next=NULL;
      this->child=NULL;
    }
};

void flat(ListNode *head,ListNode *parent)
{
    //if node child is present then
    //flatten it
    if(head->child!=NULL)
        {
            flat(head->child,head->next);
            head->next=head->child;
            head->child=NULL;
            head->next->prev=head;
        }
     if(head->next==NULL)
        {
            if(parent!=NULL)
            {
                head->next=parent;
                parent->prev=head;
            }
        }
        else
           flat(head->next,parent);
}
ListNode* flatten(ListNode* head) 
{
        if(head==NULL)
               return head;
         flat(head,NULL);
        return head;
}

//function to traverse a linked 
//list
void linkedListTraversal(ListNode *head)
{
    ListNode *temp=head;
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
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->child=new ListNode(3);

    ListNode *list=flatten(head);
    linkedListTraversal(list);
    return 0;

}