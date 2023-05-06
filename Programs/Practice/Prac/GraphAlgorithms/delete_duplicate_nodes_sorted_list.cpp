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

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        SinglyLinkedListNode *p = temp->next;
        if (temp->data == p->data)
        {
            temp->next = p->next;
            free(p);
        }
        else
            temp = temp->next;
    }
    return head;
}

int main()
{

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 5;
    llist->insert_node(1);
    llist->insert_node(2);
    llist->insert_node(2);
    llist->insert_node(3);
    llist->insert_node(4);

    SinglyLinkedListNode *llist1 = removeDuplicates(llist->head);

    print_singly_linked_list(llist1, " ");
    cout << "\n";

    free_singly_linked_list(llist1);

    return 0;
}
