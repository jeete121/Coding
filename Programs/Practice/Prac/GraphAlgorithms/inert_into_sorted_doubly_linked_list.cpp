#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep)
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

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
    while (node)
    {
        DoublyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *head, int data)
{
    DoublyLinkedListNode *newNode = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
    DoublyLinkedListNode *prev = head, *temp = head;
    newNode->data = data;
    if (head == NULL)
    {

        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else if (head->data > data)
    {
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        while (temp != NULL && temp->data < data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->next = temp;
            prev->next = newNode;
            newNode->prev = prev;
            temp->prev = newNode;
        }
        else
        {
            newNode->next = NULL;
            prev->next = newNode;
            newNode->prev = NULL;
        }
        //return head;
    }
    return head;
}

int main()
{

    DoublyLinkedList *llist = new DoublyLinkedList();

    int llist_count = 4;

    llist->insert_node(1);
    llist->insert_node(3);
    llist->insert_node(4);
    llist->insert_node(10);

    int data = 5;

    DoublyLinkedListNode *llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ");
    cout << "\n";

    free_doubly_linked_list(llist1);

    return 0;
}
