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

//function to detect the cycle in linked list
Node *detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast)
        return NULL;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    Node *temp = head->next;
    head->next->next = new Node(0);
    head->next->next->next = new Node(4);
    head->next->next->next->next = temp;
    Node *cycle = detectCycle(head);
    if (cycle == NULL)
        cout << "No Cycle";
    else
        cout << "Cycle";
    return 0;
}