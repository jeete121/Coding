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
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
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

SinglyLinkedListNode *insertNodeAtHead(SinglyLinkedListNode *head, int data)
{
    SinglyLinkedListNode *newNode = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    if (head == NULL)
        {
            head = newNode;
            head->next=NULL;
        }
    else
    {
        SinglyLinkedListNode *temp = head;
        newNode->next = temp;
        head = newNode;
    }
    return head;
}

int main()
{

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 5;
    SinglyLinkedListNode *llist_head = insertNodeAtHead(llist->head, 383);
    llist->head = llist_head;
    llist_head = insertNodeAtHead(llist->head, 484);
    llist->head = llist_head;
    llist_head = insertNodeAtHead(llist->head, 392);
    llist->head = llist_head;
    llist_head = insertNodeAtHead(llist->head, 975);
    llist->head = llist_head;
    llist_head = insertNodeAtHead(llist->head, 321);
    llist->head = llist_head;

    print_singly_linked_list(llist->head, "\n");
    cout << "\n";

    free_singly_linked_list(llist->head);

    return 0;
}
