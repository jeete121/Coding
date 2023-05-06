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

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
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

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    int cnt1 = 0, cnt2 = 0;
    SinglyLinkedListNode *temp1 = head1, *temp2 = head2, *prev1 = head1, *prev2 = head2;
    while (temp1 != NULL)
    {
        cnt1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        cnt2++;
        temp2 = temp2->next;
    }
    if (cnt1 > cnt2)
    {
        int diff = cnt1 - cnt2;
        while (prev1 != NULL && diff > 0)
        {
            prev1 = prev1->next;
            diff--;
        }
        while (prev1 != prev2)
        {
            if (prev1->next != NULL)
                prev1 = prev1->next;
            if (prev2->next != NULL)
                prev2 = prev2->next;
        }
        return prev1->data;
    }

    else
    {
        int diff = cnt2 - cnt1;
        while (prev2 != NULL && diff > 0)
        {
            prev2 = prev2->next;
            diff--;
        }
        while (prev1 != prev2)
        {
            if (prev1->next != NULL)
                prev1 = prev1->next;
            if (prev2->next != NULL)
                prev2 = prev2->next;
        }
        return prev2->data;
    }
}

int main()
{

    int index = 2;

    SinglyLinkedList *llist1 = new SinglyLinkedList();

    int llist1_count = 3;
    llist1->insert_node(1);
    llist1->insert_node(2);
    llist1->insert_node(3);

    SinglyLinkedList *llist2 = new SinglyLinkedList();

    int llist2_count = 1;
    llist2->insert_node(1);

    SinglyLinkedListNode *ptr1 = llist1->head;
    SinglyLinkedListNode *ptr2 = llist2->head;

    for (int i = 0; i < llist1_count; i++)
    {
        if (i < index)
        {
            ptr1 = ptr1->next;
        }
    }

    for (int i = 0; i < llist2_count; i++)
    {
        if (i != llist2_count - 1)
        {
            ptr2 = ptr2->next;
        }
    }

    ptr2->next = ptr1;

    int result = findMergeNode(llist1->head, llist2->head);

    cout << result << "\n";

    return 0;
}
