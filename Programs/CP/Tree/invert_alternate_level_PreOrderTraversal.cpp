#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
};
Node *newNode(int key)
{
  Node *node=new Node;
  node->key=key;
  node->left=nullptr;
  node->right=nullptr;
  return node;
}
void LevelOrderTraversal(Node *root)
{
    if(root==nullptr)
       return;
    queue<Node*>q;
    q.push(root);
    while(q.size())
      {
          Node *curr=q.front();
          q.pop();
          cout<<curr->key<<" ";
          if(curr->left)
            q.push(curr->left);
          if(curr->right)
            q.push(curr->right);
      }
}
void invertTree(Node *first,Node *second,bool level)
{
    if(!first||!second)
       return;
    if(level)
      swap(first->key,second->key);
    invertTree(first->left,second->right,!level);
    invertTree(first->right,second->left,!level);
}
void invertBinaryTree(Node *root)
{
    invertTree(root->left,root->right,true);
}
int main()
{
	Node* root = nullptr;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);
	root->right->left->left = newNode(12);
	root->right->left->right = newNode(13);
	root->right->right->left = newNode(14);
	root->right->right->right = newNode(15);
	invertBinaryTree(root);
	LevelOrderTraversal(root);
	return 0;
}