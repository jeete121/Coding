#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left;
    Node *right;
};
Node* newNode(int key)
{
	Node* node = new Node;
	node->value = key;
	node->left = node->right = nullptr;
	return node;
}
bool isBST(Node *n,int min,int max)
{
    if(n==nullptr)
       return true;
    if(n->value<min||n->value>max)
      return false;
    return isBST(n->left,min,n->value)&&isBST(n->right,n->value+1,max);
}
bool isBST(Node *n)
{
    return isBST(n,INT_MIN,INT_MAX);
}
int main()
{
   Node *root=nullptr;
	root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(8);
    if(isBST(root))
      cout<<"Tree is a BST\n";
    else
      cout<<"Tree is not a BST\n";
   return 0;
}