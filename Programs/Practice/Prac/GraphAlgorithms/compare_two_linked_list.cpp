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
bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    if (head1 == NULL && head2 == NULL)
        return true;
    if (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
            return compare_lists(head1->next, head2->next);
        else
            return false;
    }
    else
        return false;
}

int main()
{

    SinglyLinkedList *llist1 = new SinglyLinkedList();

    int llist1_count = 3;
    llist1->insert_node(1);
    llist1->insert_node(2);
    llist1->insert_node(3);

    SinglyLinkedList *llist2 = new SinglyLinkedList();

    int llist2_count = 4;
    llist2->insert_node(1);
    llist2->insert_node(2);
    llist2->insert_node(3);
    llist2->insert_node(4);

    bool result = compare_lists(llist1->head, llist2->head);

    cout << result << "\n";

    return 0;
}
