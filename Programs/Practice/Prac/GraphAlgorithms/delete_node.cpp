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

SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *head, int position)
{
    if (head == NULL || position < 0)
        return head;
    SinglyLinkedListNode *temp = head, *prev = NULL;
    int p = 0;
    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    else
    {
        while (temp != NULL && p < position)
        {
            prev = temp;
            temp = temp->next;
            p++;
        }
        if (p == position)
        {
            prev->next = temp->next;
            free(temp);
        }
        return head;
    }
}

int main()
{

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 4;

    llist->insert_node(0);
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(3);

    int position = 2;

    SinglyLinkedListNode *llist1 = deleteNode(llist->head, position);

    print_singly_linked_list(llist1, " ");
    cout << "\n";

    free_singly_linked_list(llist1);

    return 0;
}
