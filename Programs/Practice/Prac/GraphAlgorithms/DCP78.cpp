#include <bits/stdc++.h>
using namespace std;
//Struture of  node
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//function to traverse a linked
//list
void linkedListTraversal(Node *head)
{
    Node *temp = head;
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

//function to merge two sorted lists
Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    Node *temp1 = l1, *temp2 = l2, *root = NULL, *temp;
    int flag = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            if (flag == 0)
            {
                flag = 1;
                root = temp1;
                temp = root;
            }
            else
            {
                temp->next = temp1;

                temp = temp->next;
            }
            temp1 = temp1->next;
        }
        else
        {
            if (flag == 0)
            {
                flag = 1;
                root = temp2;
                temp = root;
            }
            else
            {
                temp->next = temp2;

                temp = temp->next;
            }
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
        temp->next = temp1;
    if (temp2 != NULL)
        temp->next = temp2;
    return root;
}

//function to merge k sorted list
Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    Node *l = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        //merge two lists
        Node *temp1 = lists[i];
        l = merge(l, temp1);
    }
    return l;
}
int main()
{

    //list 1: 1->3->4
    Node *l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(4);

    //list 2: 3->5->6
    Node *l2 = new Node(3);
    l2->next = new Node(5);
    l2->next->next = new Node(6);

    //list 3: 2->4->5->7
    Node *l3 = new Node(2);
    l3->next = new Node(4);
    l3->next->next = new Node(5);
    l3->next->next->next = new Node(7);

    //vector to hold the all lists
    vector<Node *> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    //call for mergeKLists
    Node *node = mergeKLists(lists);
    cout << "New list\n";
    linkedListTraversal(node);
    return 0;
}
