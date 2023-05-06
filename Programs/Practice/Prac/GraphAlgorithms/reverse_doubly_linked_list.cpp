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

DoublyLinkedListNode *reverse(DoublyLinkedListNode *head)
{
    DoublyLinkedListNode *temp = head, *prev = NULL, *next;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
    return prev;
}

int main()
{

    DoublyLinkedList *llist = new DoublyLinkedList();

    int llist_count = 4;


    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);
    llist->insert_node(4);

    DoublyLinkedListNode *llist1 = reverse(llist->head);

    print_doubly_linked_list(llist1, " ");
    cout << "\n";

    free_doubly_linked_list(llist1);

    return 0;
}
