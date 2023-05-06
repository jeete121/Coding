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

bool isIdentical(Node *root1,Node *root2)
{
    if(root1==nullptr&&root2==nullptr)
       return true;
    return ((root1&&root2)&&(root1->key==root2->key)&&isIdentical(root1->left,root1->left)&&isIdentical(root1->right,root2->right));

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
    Node* y = nullptr;
    y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(25);
    if (isIdentical(x, y))
        cout << "Given binary Trees are identical";
    else
        cout << "Given binary Trees are not identical";
    return 0;
}