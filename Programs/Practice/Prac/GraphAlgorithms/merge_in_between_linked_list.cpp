#include <bits/stdc++.h>
using namespace std;
//Struture of  node
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *prev = NULL;
    ListNode *temp = list1;
    int i = 0;
    while (i < a)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = list2;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    while (i < b)
    {
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    return list1;
}
//function to traverse a linked
//list
void linkedListTraversal(ListNode *head)
{
    ListNode *temp = head;
    //iterate till we reach end of the linked
    //list
    while (temp != NULL)
    {
        //print the current
        //node data
        cout << temp->data;
        //move to next node

        temp = temp->next;
        if (temp != NULL)
            cout << ", ";
    }
}
int main()
{
    ListNode *list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    int a = 3, b = 4;

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    ListNode *merge = mergeInBetween(list1, a, b, list2);
    cout << "[";
    linkedListTraversal(merge);
    cout << "]";
    return 0;
}