#include <bits/stdc++.h>
using namespace std;
struct Node 
{
  int key;
  Node *left,*right;
  Node(int key)
  {
  this->key=key;
  this->left=nullptr;
  this->right=nullptr;
  }

};
void deleteTree(Node* &root)
{
    if(root==nullptr)
      return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root=nullptr;
}
int main()
{
    Node* x = nullptr;
    x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);
    deleteTree(x);
    if(x==nullptr)
      cout<<"Tree is Succesfully deleted";
    return 0;
}