#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void topView(Node *root)
{
    if (root == NULL)
        return;
    map<int, Node *> ump;
    queue<pair<int, Node *>> q;

    q.push(make_pair(0, root));
    while (!q.empty())
    {
        pair<int, Node *> i = q.front();
        q.pop();
        if (!i.second)
            continue;
        ump.insert(i);
        q.push(make_pair(i.first - 1, i.second->left));
        q.push(make_pair(i.first + 1, i.second->right));
    }
    for (auto i : ump)
        cout << i.second->data << " ";
}
int main()
{

    int n = 6;
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);

    topView(root);

    return 0;
}
