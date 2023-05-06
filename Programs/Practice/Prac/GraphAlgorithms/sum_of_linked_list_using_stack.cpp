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

//Function to reverse the linklist
Node *reverseList(Node *head)
{
    if(head==NULL)
       return head;
    Node *curr=head,*prev=NULL,*temp=head;
    while(curr!=NULL)
      {
         temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
      }
    return prev;
}
//function used for sum two linked list
Node* sumTwoList(Node *l1, Node *l2) 
{
        // base case
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        // create two stack
        stack<Node*> s1;
        stack<Node*> s2;
        // iterate till end of l1
        while (l1 != NULL) {
            // add value in stack
            s1.push(l1);
            l1 = l1->next;

        }
        // iterate till end of l2
        while (l2 != NULL) {
            // add value in stack
            s2.push(l2);
            l2 = l2->next;

        }
        int carry = 0;
        Node *root =NULL;
        Node *tmp = NULL;
        // iterate till both not empty
        while (!s1.empty() && !s2.empty())
         {
            Node *n1 = s1.top();
            s1.pop();
            Node *n2 = s2.top();
            s2.pop();
            int sum = n1->data + n2->data + carry;
            n1->data = sum % 10;
            if (root ==NULL) {
                root = n1;
                tmp = n1;
            } else {
                tmp->next = n1;
                tmp = n1;
            }
            carry = sum / 10;
        }
        // if s1 not empty
        while (!s1.empty()) {
            Node *n1 = s1.top();
            s1.pop();
            int sum = n1->data + carry;
            n1->data = sum % 10;
            tmp->next = n1;
            tmp = n1;
            carry = sum / 10;
        }
        // if s2 not empty
        while (!s2.empty()) {
            Node *n2 = s2.top();
            s2.pop();
            int sum = n2->data + carry;
            n2->data = sum % 10;
            tmp->next = n2;
            tmp = n2;
            carry = sum / 10;
        }
        // carry is still
        if (carry > 0) {
            tmp->next = new Node(carry);
            tmp = tmp->next;
        }
        tmp->next = NULL;
        //reverse the list
        Node *reverse=reverseList(root);
        return reverse;
}
int main()
{
    // first linked list
    Node *l1 = new Node(9);
    l1->next = new Node(8);
    l1->next->next = new Node(8);
    l1->next->next->next = new Node(4);

    // second linked list
    Node *l2 = new Node(5);
    l2->next = new Node(2);
    l2->next->next = new Node(8);
    //sum of both list
    Node *sum = sumTwoList(l1, l2);
    // traversal the sum list
    linkedListTraversal(sum);
}