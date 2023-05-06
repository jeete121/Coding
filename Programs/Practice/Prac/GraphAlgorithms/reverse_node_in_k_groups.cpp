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

Node *reverseKGroup(Node *head, int k)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    int count = 0;

    Node *temp = head;
    int cnt = 0;

    // Checking if number of nodes is a multiple of k or not
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // if not multiple of k then don't reverse the remaining nodes
    if (cnt < k)
    {
        return head;
    }

    //Reverse first k nodes
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}
void printLinkedList(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL)
    {

        cout << temp->data;

        temp = temp->next;
        if (temp != NULL)
            cout << "->";
    }
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 3;

    head = reverseKGroup(head, k);

    printLinkedList(head);
    return 0;
}