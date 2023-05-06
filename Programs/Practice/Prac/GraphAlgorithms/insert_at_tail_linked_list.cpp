#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;

    SinglyLinkedList()
    {
        this->head = nullptr;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep)
{
    while (node)
    {
        cout << node->data;

        node = node->next;

        if (node)
        {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    SinglyLinkedListNode *temp = head;
    SinglyLinkedListNode *newNode = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 5;

    SinglyLinkedListNode *llist_head = insertNodeAtTail(llist->head, 141);
    llist->head = llist_head;
    llist_head = insertNodeAtTail(llist->head, 302);
    llist->head = llist_head;
    llist_head = insertNodeAtTail(llist->head, 164);
    llist->head = llist_head;
    llist_head = insertNodeAtTail(llist->head, 530);
    llist->head = llist_head;
    llist_head = insertNodeAtTail(llist->head, 474);
    llist->head = llist_head;

    print_singly_linked_list(llist->head, "\n");
    cout << "\n";

    free_singly_linked_list(llist->head);

    return 0;
}
