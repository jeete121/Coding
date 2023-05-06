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

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
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

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *head, int data, int position)
{
    SinglyLinkedListNode *temp = head, *prev = NULL;
    SinglyLinkedListNode *newNode = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
        return newNode;
    }
    while (temp != NULL && position)
    {
        prev = temp;
        temp = temp->next;
        position--;
    }
    newNode->next = temp;
    prev->next = newNode;
    return head;
}

int main()
{

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 3;
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);

    int data = 4;

    int position = 2;

    SinglyLinkedListNode *llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ");
    cout << "\n";

    free_singly_linked_list(llist_head);

    return 0;
}
