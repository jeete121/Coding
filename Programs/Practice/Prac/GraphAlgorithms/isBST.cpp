#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
bool BST(Node *root, int min1, int max1)
{
    if (root == NULL)
        return true;
    if (root->data <= min1 || root->data >= max1)
        return false;
    return BST(root->left, min1, root->data) && BST(root->right, root->data, max1);
}
bool checkBST(Node *root)
{
    return BST(root, -10001, 10001);
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);

    if (checkBST(root))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}