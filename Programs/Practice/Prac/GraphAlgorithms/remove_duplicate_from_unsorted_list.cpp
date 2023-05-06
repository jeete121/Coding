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
Node *removeDuplicateElement(Node *head)
{

        set<int> set;
        // If list is null
        if (head ==NULL) {
            return head;
        }

        Node *root = head;
        Node *prev = root;
        // Iterate till end of list
        while (root != NULL) {
            if (set.find(root->data)!=set.end()) {
                prev->next = root->next;
            }
            set.insert(prev->data);
            prev = root;
            root = root->next;
        }
        return head;
}

int main()
{
        Node * l = new Node(1);
        l->next = new Node(2);
        l->next->next = new Node(1);
        l->next->next->next = new Node(4);
        l->next->next->next->next = new Node(2);
        l->next->next->next->next->next = new Node(5);
        l->next->next->next->next->next->next = new Node(4);
        Node *node = removeDuplicateElement(l);
        cout<<"After Removing :";
        linkedListTraversal(node);
}
