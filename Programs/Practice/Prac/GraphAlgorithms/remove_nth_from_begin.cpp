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

//function to remove nth node from beginning

Node* removetNthNode(Node* head, int n) 
{
        // If list is nullptr
        if (head == NULL || n == 0) {
            return head;
        }
        // if delete first element
        // Base case
        if (n == 1) {
            return head->next;
        }

        int count = 0;
        Node *root = head;
        Node *prev = head;
        while (root != NULL) {
            count++;
            // if found nth then delete
            if (count == n) {
                prev->next = root->next;
                free(root);
                break;
            }
            // change previous
            prev = root;
            // head->next
            root = root->next;
        }
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
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  int n=3;
  head=removetNthNode(head,n);
  cout<<"After Removing \n";
  linkedListTraversal(head);
  return 0;
}