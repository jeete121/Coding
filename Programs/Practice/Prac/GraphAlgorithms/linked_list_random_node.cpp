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

Node *temp;

//function to return the random node
int getRandom()
{
    Node *curr = temp, *res;
    int n = 1;
    while (curr)
    {
        if (rand() % n == 0)
            res = curr;
        curr = curr->next;
        n++;
    }
    return res->data;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    temp = head;

    cout << getRandom() << " ";

    return 0;
}