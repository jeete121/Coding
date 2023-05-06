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
//function to find list from middle
Node * findMiddleElement(Node *head) 
{
      Node *fast = head;
      Node *slow = head;
        // iterate till end of list
        // and move one pointer
        // once and one pointer twice
        while (fast != NULL) {
            fast = fast->next;
            if (fast !=NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
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
     Node *l = new Node(1);
     l->next = new Node(2);
     l->next->next = new Node(3);
     l->next->next->next = new Node(4);
     l->next->next->next->next = new Node(5);
     Node *fmiddle = findMiddleElement(l);
     linkedListTraversal(fmiddle);
}

