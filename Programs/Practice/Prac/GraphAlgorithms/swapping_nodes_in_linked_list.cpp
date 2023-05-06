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
ListNode *swapNodes(ListNode *head, int k)
{
    int n = 0;
    ListNode *temp = head, *temp1 = head, *temp3 = NULL;

    while (temp != NULL)
    {
        n++;
        if (n == k)
        {
            temp3 = temp;
        }
        temp = temp->next;
    }

    int y = n - k + 1;

    while (temp1 != NULL)
    {
        y--;
        if (y == 0)
        {
            break;
        }
        temp1 = temp1->next;
    }

    swap(temp1->data, temp3->data);
    return head;
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
        cout << temp->data << " ";
        //move to next node
        temp = temp->next;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    head = swapNodes(head, k);

    linkedListTraversal(head);

    return 0;
}