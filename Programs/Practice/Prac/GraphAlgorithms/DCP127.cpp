#include <bits/stdc++.h>
using namespace std;

//Struture of  node
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *addTwoNumbers(Node *l1, Node *l2)
{
    int x = 0, y = 0, z, l = 0;
    Node *temp1 = l1, *temp2 = l2, *start = NULL, *temp;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 != NULL)
        {
            x = temp1->data;
            temp1 = temp1->next;
        }
        else if (temp1 == NULL)
            x = 0;
        if (temp2 != NULL)
        {
            y = temp2->data;
            temp2 = temp2->next;
        }
        else if (temp2 == NULL)
            y = 0;
        z = x + y + l;
        Node *newNode = new Node(z % 10);
        newNode->next = NULL;
        if (start == NULL)
        {
            start = newNode;
            temp = start;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
        l = z / 10;
    }
    if (l > 0)
    {
        Node *newNode = new Node(l);
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return start;
}

//function to traverse a linked
//list
void linkedListTraversal(Node *head)
{
    Node *temp = head;
    //iterate till we reach end of the linked
    //list
    while (temp != NULL)
    {
        //print the current
        //node data
        cout << temp->data << " ";
        //move to next node
        temp = temp->next;
    }
}
int main()
{
    Node *head1 = new Node(9);
    head1->next = new Node(9);

    Node *head2 = new Node(5);
    head2->next = new Node(2);

    Node *add = addTwoNumbers(head1, head2);

    linkedListTraversal(add);
    return 0;
}