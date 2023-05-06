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
int getNode(SinglyLinkedListNode *head, int p)
{
    int cnt = 0;
    SinglyLinkedListNode *temp = head, *temp1 = head;
    if (head == NULL)
        return 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int x = cnt - p - 1;
    while (x--)
        temp1 = temp1->next;
    return temp1->data;
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 3;
    llist->insert_node(3);
    llist->insert_node(2);
    llist->insert_node(1);

    int position = 2;

    int result = getNode(llist->head, position);

    cout << result << "\n";

    return 0;
}
